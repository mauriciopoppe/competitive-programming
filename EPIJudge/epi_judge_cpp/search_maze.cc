#include <istream>
#include <string>
#include <vector>
#include <unordered_map>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::vector;
enum class Color { kWhite, kBlack };
struct Coordinate {
  bool operator==(const Coordinate& that) const {
    return x == that.x && y == that.y;
  }

  int x, y;
};
vector<Coordinate> SearchMaze(vector<vector<Color>> maze, const Coordinate& s,
                              const Coordinate& e) {
  vector<int> dx = {-1, 0, 0, 1};
  vector<int> dy = {0, 1, -1, 0};

  typedef pair<int, int> pii;
  map<pii, pii> parent;
  parent[make_pair(s.x, s.y)] = make_pair(-1, -1);

  queue<pii> q;
  q.push(make_pair(s.x, s.y));

  function<bool(pii)> valid = [&maze](pii cand) -> bool {
    bool inbounds = cand.first >= 0 && cand.second >= 0 && cand.first < maze.size() && cand.second < maze[0].size();
    if (!inbounds) return false;
    return maze[cand.first][cand.second] == Color::kWhite;
  };

  while (!q.empty()) {
    pii top = q.front();
    q.pop();

    for (int k = 0; k < 4; k += 1) {
      pii cand = { top.first + dx[k], top.second + dy[k] };
      if (valid(cand) && parent.find(cand) == parent.end()) {
        parent[cand] = top;
        q.push(cand);
      }
    }
  }

  vector<Coordinate> output;
  if (parent.find(pii(e.x, e.y)) == parent.end()) {
    return output;
  }

  pii it = pii(e.x, e.y);
  while (it.first != -1) {
    output.push_back(Coordinate{it.first, it.second});
    it = parent[it];
  }
  reverse(output.begin(), output.end());
  return output;
}

namespace test_framework {
template <>
struct SerializationTrait<Color> : SerializationTrait<int> {
  using serialization_type = Color;

  static serialization_type Parse(const json& json_object) {
    return static_cast<serialization_type>(
        SerializationTrait<int>::Parse(json_object));
  }
};
}  // namespace test_framework

namespace test_framework {
template <>
struct SerializationTrait<Coordinate> : UserSerTrait<Coordinate, int, int> {
  static std::vector<std::string> GetMetricNames(const std::string& arg_name) {
    return {};
  }

  static std::vector<int> GetMetrics(const Coordinate& x) { return {}; }
};
}  // namespace test_framework

bool PathElementIsFeasible(const vector<vector<Color>>& maze,
                           const Coordinate& prev, const Coordinate& cur) {
  if (!(0 <= cur.x && cur.x < maze.size() && 0 <= cur.y &&
        cur.y < maze[cur.x].size() && maze[cur.x][cur.y] == Color::kWhite)) {
    return false;
  }
  return cur == Coordinate{prev.x + 1, prev.y} ||
         cur == Coordinate{prev.x - 1, prev.y} ||
         cur == Coordinate{prev.x, prev.y + 1} ||
         cur == Coordinate{prev.x, prev.y - 1};
}

bool SearchMazeWrapper(TimedExecutor& executor,
                       const vector<vector<Color>>& maze, const Coordinate& s,
                       const Coordinate& e) {
  vector<vector<Color>> copy = maze;

  auto path = executor.Run([&] { return SearchMaze(copy, s, e); });

  if (path.empty()) {
    return s == e;
  }

  if (!(path.front() == s) || !(path.back() == e)) {
    throw TestFailure("Path doesn't lay between start and end points");
  }

  for (size_t i = 1; i < path.size(); i++) {
    if (!PathElementIsFeasible(maze, path[i - 1], path[i])) {
      throw TestFailure("Path contains invalid segments");
    }
  }

  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "maze", "s", "e"};
  return GenericTestMain(args, "search_maze.cc", "search_maze.tsv",
                         &SearchMazeWrapper, DefaultComparator{}, param_names);
}
