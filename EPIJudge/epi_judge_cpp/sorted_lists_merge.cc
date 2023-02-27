#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {
  // TODO - you fill in here.
  shared_ptr<ListNode<int>> head = make_shared<ListNode<int>>(ListNode<int>(0));
  shared_ptr<ListNode<int>> l = L1;
  shared_ptr<ListNode<int>> r = L2;

  auto it = head;

  while (l && r) {
    if (l->data < r->data) {
      it->next = l;
      l = l->next;
    } else {
      it->next = r;
      r = r->next;
    }

    it = it->next;
  }

  while (l) {
    it->next = l;
    it = it->next;
    l = l->next;
  }

  while (r) {
    it->next = r;
    it = it->next;
    r = r->next;
  }

  return head->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "sorted_lists_merge.cc",
                         "sorted_lists_merge.tsv", &MergeTwoSortedLists,
                         DefaultComparator{}, param_names);
}
