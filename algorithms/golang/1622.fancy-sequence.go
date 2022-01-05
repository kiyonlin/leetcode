/*
 * @lc app=leetcode id=1622 lang=golang
 *
 * [1622] Short Encoding of Words
 *
 * Fancy Sequence
 *
 * algorithms
 * Hard (15.34%)
 * Total Accepted:    6.2K
 * Total Submissions: 40.4K
 * Testcase Example:  '["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
 * [[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]'
 *
 * Write an API that generates fancy sequences using the append, addAll, and multAll operations.
 *
 * Implement the Fancy class:
 *
 * Fancy() Initializes the object with an empty sequence.
 * void append(val) Appends an integer val to the end of the sequence.
 * void addAll(inc) Increments all existing values in the sequence by an integer inc.
 * void multAll(m) Multiplies all existing values in the sequence by an integer m.
 * int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1.
 *
 * Example:
 *
 * Input
 * ["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
 * [[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
 * Output
 * [null, null, null, null, null, 10, null, null, null, 26, 34, 20]
 *
 * Explanation
 * Fancy fancy = new Fancy();
 * fancy.append(2);   // fancy sequence: [2]
 * fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
 * fancy.append(7);   // fancy sequence: [5, 7]
 * fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
 * fancy.getIndex(0); // return 10
 * fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
 * fancy.append(10);  // fancy sequence: [13, 17, 10]
 * fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
 * fancy.getIndex(0); // return 26
 * fancy.getIndex(1); // return 34
 * fancy.getIndex(2); // return 20
 *
 * Note:
 *
 * 1 <= val, inc, m <= 100
 * 0 <= idx <= 10^5
 * At most 10^5 calls total will be made to append, addAll, multAll, and getIndex.
 *
 *
 */

package main

import "fmt"

const crt = 84467440737095516 // max(uint64) = 8446744073709551615
const md = 1000000007

type Oper struct {
	o int8
	v int8
	h int32
}

type Fancy struct {
	arr []int8
	opr []Oper
	cas map[int]int
}

func Constructor() Fancy {
	return Fancy{}
}

func (this *Fancy) Append(val int) {
	this.arr = append(this.arr, int8(val))
}

func printList(l Fancy) {

	for _, v := range l.arr {

		fmt.Print(v, " ")
	}

	fmt.Println()
}

func (this *Fancy) AddAll(inc int) {

	this.opr = append(this.opr, Oper{-2, int8(inc), int32(len(this.arr))})
	this.cas = make(map[int]int)
}

func (this *Fancy) MultAll(m int) {

	this.opr = append(this.opr, Oper{-1, int8(m), int32(len(this.arr))})
	this.cas = make(map[int]int)
}

func (this *Fancy) GetIndex(idx int) int {

	if idx < 0 || idx >= len(this.arr) {
		return -1
	}

	if val, ok := this.cas[idx]; ok {
		return val
	}

	var vv uint64

	vv = uint64(this.arr[idx])

	for _, v := range this.opr {

		if idx >= int(v.h) {
			continue
		}

		switch os := v.o; os {
		case -2:
			vv += uint64(v.v)
		case -1:
			vv *= uint64(v.v)
		}

		if vv > crt {
			vv = vv % md
		}
	}

	if vv > md {
		vv = vv % md
	}

	if this.cas == nil {
		this.cas = make(map[int]int)
	}

	this.cas[idx] = int(vv)

	return int(vv)
}
