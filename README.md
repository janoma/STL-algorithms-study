# Study of STL's `<algorithm>` header [![Build Status](https://travis-ci.org/janoma/STL-algorithms-study.svg?branch=master)](https://travis-ci.org/janoma/STL-algorithms-study)
To the point: examples to study the functionality provided by the `<algorithm>`
header in C++.

Current completion status: 16.86% :grin: (14/83, see tables below).  __Pull requests are
welcome!__

## Cloning/running
Although many functions came before it, I'm using C++11 for the tests. That would be
the only requirement, along with
[Boost.Test](http://www.boost.org/doc/libs/1_60_0/libs/test/doc/html/index.html).
```
$ git clone https://github.com/janoma/stl-algorithm-study.git
$ cd stl-algorithm-study
$ cmake .
$ make
$ make test
```

## Index
The following list maps function names to the `.cpp` file in which they are
tested. Function names are linked to their entry in [devdocs.io](https://devdocs.io).

### Non-modifying sequence operations
Completion status: 37.5%

| Function name | Test file |
| ------------- | --------- |
| [`all_of`](https://devdocs.io/cpp/algorithm/all_any_none_of) (C++11) | [all_of.cpp](test/all_of.cpp) |
| [`any_of`](https://devdocs.io/cpp/algorithm/all_any_none_of) (C++11) | [all_of.cpp](test/all_of.cpp) |
| [`none_of`](https://devdocs.io/cpp/algorithm/all_any_none_of) (C++11) | [all_of.cpp](test/all_of.cpp) |
| [`for_each`](https://devdocs.io/cpp/algorithm/for_each) | [for_each.cpp](test/for_each.cpp) |
| [`count`](https://devdocs.io/cpp/algorithm/count) | [count.cpp](test/count.cpp) |
| [`count_if`](https://devdocs.io/cpp/algorithm/count) | [count.cpp](test/count.cpp) |
| [`mismatch`](https://devdocs.io/cpp/algorithm/mismatch) | _pending_ |
| [`equal`](https://devdocs.io/cpp/algorithm/equal) | _pending_ |
| [`find`](https://devdocs.io/cpp/algorithm/find) | _pending_ |
| [`find_if`](https://devdocs.io/cpp/algorithm/find) | _pending_ |
| [`find_if_not`](https://devdocs.io/cpp/algorithm/find) (C++11) | _pending_ |
| [`find_end`](https://devdocs.io/cpp/algorithm/find_end) | _pending_ |
| [`find_first_of`](https://devdocs.io/cpp/algorithm/find_first_of) | _pending_ |
| [`adjacent_find`](https://devdocs.io/cpp/algorithm/adjacent_find) | _pending_ |
| [`search`](https://devdocs.io/cpp/algorithm/search) | _pending_ |
| [`search_n`](https://devdocs.io/cpp/algorithm/search_n) | _pending_ |

### Modifying sequence operations
Completion status: 0%

| Function name | Test file |
| ------------- | --------- |
| [`copy`](https://devdocs.io/cpp/algorithm/copy) | _pending_ |
| [`copy_if`](https://devdocs.io/cpp/algorithm/copy) (C++11) | _pending_ |
| [`copy_n`](https://devdocs.io/cpp/algorithm/copy_n) (C++11) | _pending_ |
| [`copy_backward`](https://devdocs.io/cpp/algorithm/copy_backward) | _pending_ |
| [`move`](https://devdocs.io/cpp/algorithm/move) (C++11) | _pending_ |
| [`move_backward`](https://devdocs.io/cpp/algorithm/move_backward) (C++11) | _pending_ |
| [`fill`](https://devdocs.io/cpp/algorithm/fill) | _pending_ |
| [`fill_n`](https://devdocs.io/cpp/algorithm/fill_n) | _pending_ |
| [`transform`](https://devdocs.io/cpp/algorithm/transform) | _pending_ |
| [`generate`](https://devdocs.io/cpp/algorithm/generate) | _pending_ |
| [`generate_n`](https://devdocs.io/cpp/algorithm/generate_n) | _pending_ |
| [`remove`](https://devdocs.io/cpp/algorithm/remove) | _pending_ |
| [`remove_if`](https://devdocs.io/cpp/algorithm/remove) | _pending_ |
| [`remove_copy`](https://devdocs.io/cpp/algorithm/remove_copy) | _pending_ |
| [`remove_copy_if`](https://devdocs.io/cpp/algorithm/remove_copy) | _pending_ |
| [`replace`](https://devdocs.io/cpp/algorithm/replace) | _pending_ |
| [`replace_if`](https://devdocs.io/cpp/algorithm/replace) | _pending_ |
| [`replace_copy`](https://devdocs.io/cpp/algorithm/replace_copy) | _pending_ |
| [`replace_copy_if`](https://devdocs.io/cpp/algorithm/replace_copy) | _pending_ |
| [`swap`](https://devdocs.io/cpp/algorithm/swap) | _pending_ |
| [`swap_ranges`](https://devdocs.io/cpp/algorithm/swap_ranges) | _pending_ |
| [`iter_swap`](https://devdocs.io/cpp/algorithm/iter_swap) | _pending_ |
| [`reverse`](https://devdocs.io/cpp/algorithm/reverse) | _pending_ |
| [`reverse_copy`](https://devdocs.io/cpp/algorithm/reverse_copy) | _pending_ |
| [`rotate`](https://devdocs.io/cpp/algorithm/rotate) | _pending_ |
| [`rotate_copy`](https://devdocs.io/cpp/algorithm/rotate_copy) | _pending_ |
| [`shuffle`](https://devdocs.io/cpp/algorithm/random_shuffle) (C++11) | _pending_ |
| [`unique`](https://devdocs.io/cpp/algorithm/unique) | _pending_ |
| [`unique_copy`](https://devdocs.io/cpp/algorithm/unique_copy) | _pending_ |

### Partitioning operations
Completion status: 0%

| Function name | Test file |
| ------------- | --------- |
| [`is_partitioned`](https://devdocs.io/cpp/algorithm/is_partitioned) (C++11) | _pending_ |
| [`partition`](https://devdocs.io/cpp/algorithm/partition) | _pending_ |
| [`partition_copy`](https://devdocs.io/cpp/algorithm/partition_copy) (C++11) | _pending_ |
| [`stable_partition`](https://devdocs.io/cpp/algorithm/stable_partition) | _pending_ |
| [`partition_point`](https://devdocs.io/cpp/algorithm/partition_point) (C++11) | _pending_ |

### Sorting operations (on sorted ranges)
Completion status: 28.5%

| Function name | Test file |
| ------------- | --------- |
| [`is_sorted`](https://devdocs.io/cpp/algorithm/is_sorted) (C++11) | [is_sorted.cpp](test/is_sorted.cpp) |
| [`is_sorted_until`](https://devdocs.io/cpp/algorithm/is_sorted_until) (C++11) | [is_sorted.cpp](test/is_sorted.cpp) |
| [`sort`](https://devdocs.io/cpp/algorithm/sort) | _pending_ |
| [`partial_sort`](https://devdocs.io/cpp/algorithm/partial_sort) | _pending_ |
| [`partial_sort_copy`](https://devdocs.io/cpp/algorithm/partial_sort_copy) | _pending_ |
| [`stable_sort`](https://devdocs.io/cpp/algorithm/stable_sort) | _pending_ |
| [`nth_element`](https://devdocs.io/cpp/algorithm/nth_element) | _pending_ |

### Binary search operations (on sorted ranges)
Completion status: 0%

| Function name | Test file |
| ------------- | --------- |
| [`lower_bound`](https://devdocs.io/cpp/algorithm/lower_bound) | _pending_ |
| [`upper_bound`](https://devdocs.io/cpp/algorithm/upper_bound) | _pending_ |
| [`binary_search`](https://devdocs.io/cpp/algorithm/binary_search) | _pending_ |
| [`equal_range`](https://devdocs.io/cpp/algorithm/equal_range) | _pending_ |

### Set operations (on sorted ranges)
Completion status: 0%

| Function name | Test file |
| ------------- | --------- |
| [`merge`](https://devdocs.io/cpp/algorithm/merge) | _pending_ |
| [`inplace_merge`](https://devdocs.io/cpp/algorithm/inplace_merge) | _pending_ |
| [`includes`](https://devdocs.io/cpp/algorithm/includes) | _pending_ |
| [`set_difference`](https://devdocs.io/cpp/algorithm/set_difference) | _pending_ |
| [`set_intersection`](https://devdocs.io/cpp/algorithm/set_intersection) | _pending_ |
| [`set_symmetric_difference`](https://devdocs.io/cpp/algorithm/set_symmetric_difference) | _pending_ |
| [`set_union`](https://devdocs.io/cpp/algorithm/set_union) | _pending_ |

### Heap operations
Completion status: 0%

| Function name | Test file |
| ------------- | --------- |
| [`is_heap`](https://devdocs.io/cpp/algorithm/is_heap) (C++11) | _pending_ |
| [`is_heap_until`](https://devdocs.io/cpp/algorithm/is_heap_until) (C++11) | _pending_ |
| [`make_heap`](https://devdocs.io/cpp/algorithm/make_heap) | _pending_ |
| [`push_heap`](https://devdocs.io/cpp/algorithm/push_heap) | _pending_ |
| [`pop_heap`](https://devdocs.io/cpp/algorithm/pop_heap) | _pending_ |
| [`sort_heap`](https://devdocs.io/cpp/algorithm/sort_heap) | _pending_ |

### Minimum/maximum operations
Completion status: 60%

| Function name | Test file |
| ------------- | --------- |
| [`max`](https://devdocs.io/cpp/algorithm/max) | [minmax.cpp](test/minmax.cpp) |
| [`max_element`](https://devdocs.io/cpp/algorithm/max_element) | [minmax.cpp](test/minmax.cpp) |
| [`min`](https://devdocs.io/cpp/algorithm/min) | [minmax.cpp](test/minmax.cpp) |
| [`min_element`](https://devdocs.io/cpp/algorithm/min_element) | [minmax.cpp](test/minmax.cpp) |
| [`minmax`](https://devdocs.io/cpp/algorithm/minmax) (C++11) | [minmax.cpp](test/minmax.cpp) |
| [`minmax_element`](https://devdocs.io/cpp/algorithm/minmax_element) (C++11) | [minmax.cpp](test/minmax.cpp) |
| [`lexicographical_compare`](https://devdocs.io/cpp/algorithm/lexicographical_compare) | _pending_ |
| [`is_permutation`](https://devdocs.io/cpp/algorithm/is_permutation) (C++11) | _pending_ |
| [`next_permutation`](https://devdocs.io/cpp/algorithm/next_permutation) | _pending_ |
| [`prev_permutation`](https://devdocs.io/cpp/algorithm/prev_permutation) | _pending_ |

## License
MIT License.
