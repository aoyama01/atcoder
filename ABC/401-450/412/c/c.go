package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
	// "golang.org/x/exp/slices"
)

var sc = NewScanner()
var _r = bufio.NewReader(os.Stdin)
var _w = bufio.NewWriter(os.Stdout)

func main() {
	q := sc.int()
	fmt.Println(q)

	var a []int
	for i := 0; i < q; i++ {
		sc.sc.Scan()
		query := strings.Fields(sc.sc.Text())
		fmt.Println(query)

		switch query[0] {
		case "1":
			c, _ := strconv.Atoi(query[1])
			x, _ := strconv.Atoi(query[2])
			s := make([]int, c)
			for i := range s {
				s[i] = x
			}
			a = append(a, s...)
		case "2":
			k, _ := strconv.Atoi(query[1])
			sum := 0
			for i := 0; i < k; i++ {
				sum += a[i]
			}
			a = a[:k]
			fmt.Println(sum)
		}
	}

}

type Sc struct{ sc *bufio.Scanner }

func NewScanner() *Sc {
	s := bufio.NewScanner(os.Stdin)
	s.Buffer(make([]byte, 4096), math.MaxInt32)
	s.Split(bufio.ScanWords)
	return &Sc{sc: s}
}
func (s *Sc) int() int       { s.sc.Scan(); v, _ := strconv.Atoi(s.sc.Text()); return v }
func (s *Sc) float() float64 { s.sc.Scan(); v, _ := strconv.ParseFloat(s.sc.Text(), 64); return v }
func (s *Sc) next() string   { s.sc.Scan(); return s.sc.Text() }
