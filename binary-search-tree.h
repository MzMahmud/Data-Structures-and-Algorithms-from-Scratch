#ifndef CPP_BINARY_SEARCH_TREE_H
#define CPP_BINARY_SEARCH_TREE_H

template<typename T>
class BinarySearchTree {
private:
    struct Node {
        T val;
        Node *left, *right;

        Node() : left(nullptr), right(nullptr) {}

        explicit Node(const T &v) : val(v), left(nullptr), right(nullptr) {}
    };

    Node *m_root;
    size_t m_size;

    Node *insert_and_get_new_root(Node *root, const T &val) {
        if (root == nullptr)
            return new Node(val);
        if (val < root->val)
            root->left = insert_and_get_new_root(root->left, val);
        else
            root->right = insert_and_get_new_root(root->right, val);
        return root;
    }

    bool contains(Node *root, const T &val) const {
        if (root == nullptr)
            return false;

        if (root->val == val)
            return true;

        return (val < root->val) ? contains(root->left, val)
                                 : contains(root->right, val);
    }

    Node *copy_and_get_new_root_from(Node *root) {
        if (root == nullptr)
            return root;
        Node *copied_root = new Node(root->val);
        copied_root->left = copy_and_get_new_root_from(root->left);
        copied_root->right = copy_and_get_new_root_from(root->right);
        return copied_root;
    }

    void free_tree(Node *root) {
        if (root == nullptr)
            return;
        free_tree(root->left);
        free_tree(root->right);
        delete root;
    }

    void print_in_order(Node *root, std::ostream &sout) const {
        if (root == nullptr)
            return;
        print_in_order(root->left, sout);
        sout << root->val << ", ";
        print_in_order(root->right, sout);
    }

    const T &find_successor(Node *root) {
        root = root->right;
        while (root->left != nullptr)
            root = root->left;
        return root->val;
    }

    Node *remove_root_and_get_new_root(Node *root) {
        Node *new_root;
        if (root->left == nullptr) {
            new_root = root->right;
            delete root;
            return new_root;
        } else if (root->right == nullptr) {
            new_root = root->left;
            delete root;
            return new_root;
        }
        T successor = find_successor(root);
        root->val = successor;
        root->right = remove_and_get_new_root(root->right, successor);
        return root;
    }

    Node *remove_and_get_new_root(Node *root, const T &val) {
        if (root == nullptr)
            return root;

        if (val == root->val)
            root = remove_root_and_get_new_root(root);
        else if (val < root->val)
            root->left = remove_and_get_new_root(root->left, val);
        else
            root->right = remove_and_get_new_root(root->right, val);
        return root;
    }

public:
    BinarySearchTree() : m_root(nullptr), m_size(0) {}

    BinarySearchTree(const BinarySearchTree<T> &other) {
        m_size = other.m_size;
        m_root = copy_and_get_new_root_from(other.m_root);
    }

    ~BinarySearchTree() {
        free_tree(m_root);
    }

    BinarySearchTree<T> &operator=(const BinarySearchTree<T> &other) {
        if (this != &other) {
            free_tree(m_root);
            m_root = copy_and_get_new_root_from(other.m_root);
            m_size = other.m_size;
        }
        return *this;
    }

    void insert(const T &val) {
        m_root = insert_and_get_new_root(m_root, val);
        m_size++;
    }

    void remove(const T &val) {
        m_root = remove_and_get_new_root(m_root, val);
        m_size--;
    }

    bool contains(const T &val) const {
        return contains(m_root, val);
    }

    size_t size() const {
        return m_size;
    }

    void print_in_order(std::ostream &sout) const {
        print_in_order(m_root, sout);
    }
};

template<typename T>
std::ostream &operator<<(std::ostream &sout, const BinarySearchTree<T> &bst) {
    bst.print_in_order(sout);
    return sout;
}

#endif //CPP_BINARY_SEARCH_TREE_H
