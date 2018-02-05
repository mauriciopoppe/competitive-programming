import (
	"math"
)

func countBits(num int) []int {
	total := make([]int, num + 1)
	total[0] = 0
	for i := 1; i <= num; i++ {
		bit := int(math.Floor(math.Log2(float64(i))))
		sub := 1 << uint(bit)
		total[i] = 1 + total[i-sub]
	}
	return total
}

