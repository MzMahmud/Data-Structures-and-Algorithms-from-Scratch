# Data Structures and Algorithms from Scratch

In this repository I am implementing the **Data Structures** and **Algorithms** I have learnt from scratch with **`C/C++`**.

# Implemented

## Data Structures
- `Dynamic Array` in `C++` as `template class`
- `Singly Linked` List without `tail` in `C`
- `Singly Linked` List with `tail` in `C++` as `template class` 
- `Stack` with __my__ `Singly Linked List` in `C++` as  `template class` 
- `Queue` with __my__ `Singly Linked List` in `C++` as `template class` 
- `Priority Queue`(Max heap) with __my__ `Dynamic Array` in `C++` as `template class`. The implementation is a bit messy as I am assuming the user has provided only an overload to `< operator` for the custom class. I am studying to find elegent way to handle this. 

## Algorithms
- Marge Sort __within__ Singly Linked List class.
- Selection Sort tamplate function with __custom compare function__ support.
    ```cpp
    template <class T>
    void selection_sort(vector<T> &a, int begin_index, int end_index,
                        bool(*compare_function)(T, T) = less_then);

    template <class T>
    void selection_sort_recursive(vector<T> &a, int begin_index, int end_index,
                                  bool (*compare_function)(T, T) = less_then);
    ```
- Bouble Sort tamplate function with __custom compare function__ support.
    ```cpp
    template <class T>
    void bouble_sort(vector<T> &a, int begin_index, int end_index,
                        bool(*compare_function)(T, T) = less_then);

    template <class T>
    void bouble_sort_recursive(vector<T> &a, int begin_index, int end_index,
                                  bool (*compare_function)(T, T) = less_then);
    ```
- Insertion Sort tamplate function with __custom compare function__ support.
    ```cpp
    template <class T>
    void insertion_sort(vector<T> &a, int begin_index, int end_index,
                        bool(*compare_function)(T, T) = less_then);

    template <class T>
    void insertion_sort_recursive(vector<T> &a, int begin_index, int end_index,
                                  bool (*compare_function)(T, T) = less_then);
    ```