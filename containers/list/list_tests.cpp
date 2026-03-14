#include <cassert>
#include <cstddef>
#include <iostream>

#include "./list.hpp"

static void test_default_constructor_and_empty_state()
{
    rub::list<int> lst;

    assert(lst.size() == 0);
    assert(lst.front() == nullptr);
    assert(lst.back() == nullptr);
    assert(lst.begin() == lst.end());
}

static void test_value_constructor()
{
    rub::list<int> lst(42);

    assert(lst.size() == 1);
    assert(lst.front() != nullptr);
    assert(lst.back() != nullptr);
    assert(lst.front() == lst.back());
    assert(lst.front()->value == 42);
    assert(lst.front()->prev == nullptr);
    assert(lst.front()->next == nullptr);
}

static void test_push_and_bidirectional_links()
{
    rub::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    assert(lst.size() == 3);
    assert(lst.front()->value == 10);
    assert(lst.back()->value == 30);

    rub::node<int>* n1 = lst.front();
    rub::node<int>* n2 = n1->next;
    rub::node<int>* n3 = n2->next;

    assert(n1->prev == nullptr);
    assert(n1->next == n2);
    assert(n2->prev == n1);
    assert(n2->next == n3);
    assert(n3->prev == n2);
    assert(n3->next == nullptr);
}

static void test_insert_middle_and_tail_update()
{
    rub::list<int> lst;
    lst.push_back(1);
    lst.push_back(3);

    rub::node<int>* first = lst.front();
    lst.insert(first, 2);

    assert(lst.size() == 3);
    assert(lst.front()->value == 1);
    assert(lst.back()->value == 3);

    rub::node<int>* n1 = lst.front();
    rub::node<int>* n2 = n1->next;
    rub::node<int>* n3 = n2->next;

    assert(n1->value == 1);
    assert(n2->value == 2);
    assert(n3->value == 3);
    assert(n2->prev == n1);
    assert(n2->next == n3);
    assert(n3->prev == n2);

    lst.insert(lst.back(), 4);
    assert(lst.size() == 4);
    assert(lst.back()->value == 4);
    assert(lst.back()->prev->value == 3);
}

static void test_insert_null_target_is_noop()
{
    rub::list<int> lst;
    lst.push_back(7);

    lst.insert(nullptr, 99);

    assert(lst.size() == 1);
    assert(lst.front()->value == 7);
    assert(lst.back()->value == 7);
}

static void test_pop_behaviour()
{
    rub::list<int> lst;

    lst.pop_back();
    assert(lst.size() == 0);

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    lst.pop_back();
    assert(lst.size() == 2);
    assert(lst.back()->value == 2);
    assert(lst.back()->next == nullptr);

    lst.pop_back();
    assert(lst.size() == 1);
    assert(lst.front() == lst.back());
    assert(lst.front()->value == 1);

    lst.pop_back();
    assert(lst.size() == 0);
    assert(lst.front() == nullptr);
    assert(lst.back() == nullptr);
    assert(lst.begin() == lst.end());
}

static void test_iterator_forward_traversal()
{
    rub::list<int> lst;
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);

    auto it = lst.begin();
    auto ed = lst.end();

    assert(it != ed);
    assert(*it == 5);
    ++it;
    assert(*it == 6);
    it++;
    assert(*it == 7);
    ++it;
    assert(it == ed);
}

static void test_iterator_backward_from_end()
{
    rub::list<int> lst;
    lst.push_back(11);
    lst.push_back(22);
    lst.push_back(33);

    auto it = lst.end();
    --it;
    assert(*it == 33);
    --it;
    assert(*it == 22);
    it--;
    assert(*it == 11);
}

static void test_const_iteration_and_arrow_operator()
{
    rub::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);

    const rub::list<int>& clst = lst;
    auto it = clst.cbegin();
    auto ed = clst.cend();

    assert(it != ed);
    assert(*it == 100);
    assert(*it.operator->() == 100);

    ++it;
    assert(*it == 200);
    ++it;
    assert(it == ed);
}

static void test_end_tracks_live_tail()
{
    rub::list<int> lst;
    auto ed = lst.end();

    lst.push_back(9);
    lst.push_back(10);

    --ed;
    assert(*ed == 10);

    lst.pop_back();
    ed = lst.end();
    --ed;
    assert(*ed == 9);
}

int main()
{
    test_default_constructor_and_empty_state();
    test_value_constructor();
    test_push_and_bidirectional_links();
    test_insert_middle_and_tail_update();
    test_insert_null_target_is_noop();
    test_pop_behaviour();
    test_iterator_forward_traversal();
    test_iterator_backward_from_end();
    test_const_iteration_and_arrow_operator();
    test_end_tracks_live_tail();

    std::cout << "All list tests passed.\n";
    return 0;
}
