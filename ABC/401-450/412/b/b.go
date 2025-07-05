package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"

	"golang.org/x/exp/slices"
)

var sc = NewScanner()
var _r = bufio.NewReader(os.Stdin)
var _w = bufio.NewWriter(os.Stdout)

func main() {
	n := sc.int()

	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = sc.next()
	}

	count := 0
	var memo []string
	for i := 0; i < n; i++ {
		// S_i, S_j の順に連結することに注意
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}
			concatStr := s[i] + s[j]
			if !slices.Contains(memo, concatStr) {
				count++
				memo = append(memo, concatStr)
			}
		}
	}

	// fmt.Println(memo)
	fmt.Println(count)
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
