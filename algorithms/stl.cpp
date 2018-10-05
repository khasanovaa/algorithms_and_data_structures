template <typename It, typename Pred>
bool any_of(It first, It last, Pred f) {
	for (auto it = first; it != last; ++it) {
		if (f(*it)) {
			return true;
		}
	}
	return false;
}

template <typename InIter, typename OutIter, typename Predicate>
OutIter remove_copy_if(InIter first, InIter last, OutIter out, Predicate f) {
	for (auto it = first; it != last; it++) {
		if (!f(*it)) {
			*out = *it;
			out++;
		}
	}
	return out;
}

template <typename Iter>
Iter unique(Iter first, Iter last) {
	if (first == last) {
		return first;
	}

	Iter now = first;
	while (now != last) {
		if (*now != *first) {
			first++;
			*first = *now;
		}
		now++;
	}
	return ++first;
}

template <typename InIter, typename OutIter>
OutIter reverse_copy(InIter first, InIter last, OutIter out) {
	auto it = last;
	while (it != first) {
		it--;
		*out = *it;
		out++;
	}
	return out;
}

template <typename InIter1, typename InIter2, typename OutIter>
OutIter set_difference(InIter1 first1, InIter1 last1, InIter2 first2, InIter2 last2, OutIter out) {
	while (first1 != last1) {
		if (first2 == last2) {
			while (first1 != last1) {
				*out = *first1;
				first1++;
				out++;
			}
			return out;
		}
		if (*first2 > *first1) {
			*out = *first1;
			out++;
			first1++;
		}
		else if (*first2 < *first1) {
			first2++;
		}
		else if (*first2 == *first1) {
			first2++;
			first1++;
		}
	}
	return out;
}

template <typename InIter, typename OutIter, typename Predicate, typename Action>
OutIter transform_if(InIter first, InIter last, OutIter out, Predicate condition, Action f) {
	while (first != last) {
		if (condition(*first)) {
			*out = f(*first);
			out++;
		}
		first++;
	}
	return out;
}

template< class It, class T >
void fill_range(It first, It last, const T& value) {
	while (first != last) {
		*first = value;
		first++;
	}
}

template<class It1, class It2>
It2 swap_segments(It1 first1, It1 last1, It2 first2) {
	while (first1 != last1) {
		auto it = *first2;
		*first2 = *first1;
		*first1 = it;
		first2++;
		first1++;
	}
	return first2;
}

template <class It>
It rotate_range(It first, It new_first, It last) {
	if (first == last) {
		return first + (last - new_first);
	}
	auto it4 = first;
	while (it4 != new_first) {
		auto it1 = *first;
		auto it = first;
		auto it2 = last;
		it2--;
		while (it != it2) {
			auto it3 = it;
			it3++;
			*it = *(it3);
			it++;
		}
		*(it2) = it1;
		it4++;
	}

	return first + (last - new_first);
}

template<class InputIt, class T>
T accumulate_range(InputIt first, InputIt last, T init) {
	while (first != last) {
		init += *first;
		first++;
	}
	return init;
}