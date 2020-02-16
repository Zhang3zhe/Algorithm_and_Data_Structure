/**
 * Copyright (c) 2020-02 https://github.com/Zhang3zhe All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef BUBBLE_SORT_TEST_H_
#define BUBBLE_SORT_TEST_H_
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include"bubble_sort.h"

class BubbleSortTest {
 public:
	 static void TEST() {
		 std::cout << "----- BubbleSortTest: -----" << std::endl;

		 // 4组std::vector： 增序排列、降序排列、有重复数字、单元素的std::vector
		 std::list<int> data, cmp_data;

		 data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		 cmp_data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		 judge(data, cmp_data);

		 data = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		 cmp_data = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		 judge(data, cmp_data);

		 data = { 5, 5, 5, 5, 5, 4, 4, 4, 4, 4 };
		 cmp_data = { 5, 5, 5, 5, 5, 4, 4, 4, 4, 4 };
		 judge(data, cmp_data);

		 data = { 5 };
		 cmp_data = { 5 };
		 judge(data, cmp_data);

		 std::cout << "----- BubbleSortTest over, access rate is " << 100.0 * access_no / case_no << "%. -----" << std::endl;
	 }
 
 private:
	 static int case_no;
	 static int access_no;

	 static void judge(std::vector<int>& lhs, std::vector<int>& rhs) {
		 ads::bubble_sort(lhs.begin(), lhs.end());
		 std::sort(rhs.begin(), rhs.end());	   // 参考函数： std::sort()
		 ++ case_no;
		 if (lhs == rhs) {
			 std::cout << "[-->] ";
			 ++ access_no;
		 } else {
			 std::cout << "[XXX] ";
		 }
		 print(lhs);
	 }

	 static void judge(std::list<int>& lhs, std::list<int>& rhs) {
		 ads::bubble_sort(lhs.begin(), lhs.end());
		 rhs.sort();	   // 参考函数： std::sort()
		 ++case_no;
		 if (lhs == rhs) {
			 std::cout << "[-->] ";
			 ++access_no;
		 }
		 else {
			 std::cout << "[XXX] ";
		 }
		 print(lhs);
	 }

	 static void print(const std::vector<int>& nums) {
		 for (auto elem : nums) {
			 std::cout << elem << "  ";
		 }
		 std::cout << std::endl;
	 }

	 static void print(const std::list<int>& nums) {
		 for (auto elem : nums) {
			 std::cout << elem << "  ";
		 }
		 std::cout << std::endl;
	 }
};

int BubbleSortTest::case_no = 0;
int BubbleSortTest::access_no = 0;

#endif // BUBBLE_SORT_TEST_H_
