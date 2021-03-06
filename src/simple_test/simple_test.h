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
#ifndef SIMPLE_TEST_H_
#define SIMPLE_TEST_H_
#include<iostream>
#include"src/sort_algorithm/bubble_sort/bubble_sort_test.h"
#include"src/sort_algorithm/select_sort/select_sort_test.h"
#include"src/sort_algorithm/insert_sort/insert_sort_test.h"
#include"src/sort_algorithm/shell_sort/shell_sort_test.h"
#include"src/sort_algorithm/merge_sort/merge_sort_test.h"
#include"src/sort_algorithm/heap_sort/heap_sort_test.h"
#include"src/sort_algorithm/quick_sort/quick_sort_test.h"
#include"src/sort_algorithm/count_sort/count_sort_test.h"
#include"src/sort_algorithm/radix_sort/radix_sort_test.h"
#include"src/sort_algorithm/bucket_sort/bucket_sort_test.h"
#include"src/select_algorithm/select_test.h"

namespace SimpleTest {

void RUN_ALL_TESTS() {
	std::cout << "Test start!" << std::endl;
	BubbleSortTest::TEST();
	SelectSortTest::TEST();
	InsertSortTest::TEST();
	ShellSortTest::TEST();
	MergeSortTest::TEST();
	HeapSortTest::TEST();
	QuickSortTest::TEST();
	CountSortTest::TEST();
	RadixSortTest::TEST();
	BucketSortTest::TEST();
	SelectTest::TEST();
	std::cout << "All test completed!" << std::endl;
}

} // namespace SimpleTest

#endif // SIMPLE_TEST_H_
