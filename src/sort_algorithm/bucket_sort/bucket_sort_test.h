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
#ifndef BUCKET_SORT_TEST_H_
#define BUCKET_SORT_TEST_H_
#include<iostream>
#include<vector>
#include<algorithm>
#include"bucket_sort.h"

class BucketSortTest {
 public:
	 static void TEST() {
		 std::cout << "----- BucketSortTest: -----" << std::endl;

		 // 4组std::vector： 增序排列、降序排列、有重复数字、单元素的std::vector
		 std::vector<int> data, cmp_data;

		 data = { 123, 234, 345, 456, 567, 678, 789, 890, 901, 912 };
		 cmp_data = { 123, 234, 345, 456, 567, 678, 789, 890, 901, 912 };
		 judge(data, cmp_data);

		 data = { 912, 901, 890, 789, 678, 567, 456, 345, 234, 123 };
		 cmp_data = { 912, 901, 890, 789, 678, 567, 456, 345, 234, 123 };
		 judge(data, cmp_data);

		 data = { 555, 555, 544, 554, 545, 444, 455, 445, 454, 444 };
		 cmp_data = { 555, 555, 544, 554, 545, 444, 455, 445, 454, 444 };
		 judge(data, cmp_data);

		 data = { 555 };
		 cmp_data = { 555 };
		 judge(data, cmp_data);

		 std::cout << "----- BucketSortTest over, access rate is " << 100.0 * access_no / case_no << "%. -----" << std::endl;
	 }
 
 private:
	 static int case_no;
	 static int access_no;

	 static void judge(std::vector<int>& lhs, std::vector<int>& rhs) {
		 ads::bucket_sort(lhs.begin(), lhs.end(), 100, 1000);
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

	 static void print(const std::vector<int>& nums) {
		 for (auto elem : nums) {
			 std::cout << elem << "  ";
		 }
		 std::cout << std::endl;
	 }
};

int BucketSortTest::case_no = 0;
int BucketSortTest::access_no = 0;

#endif // BUCKET_SORT_TEST_H_
