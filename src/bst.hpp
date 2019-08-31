#ifndef bst_h
#define bst_h

#include <memory>
#include <iostream>

/*
  invariant: left subtree is smaller, right subtree is bigger
*/
template <class E>
class bst
{
  private:
    bst* left_;
    bst* right_;
    E key_;
    size_t size_ = 1;
    bool insertNode(bst*, const E&, bst*);

  public:
    bst(E e, bst *left=nullptr, bst *right=nullptr);
    bool contain(const E&) const;
    size_t size() const;
    virtual void insert(E);
    virtual ~bst();
    void operator=(bst) = delete;
    bst(bst&) = delete;
};

template <class E> bst<E>::bst(E k, bst* left, bst* right):left_(left), right_(right), key_(k)
{}

/*
  Implementation of the binary search
  take the root node of the tree as first paramter
  the key to insert
  and node to insert
  return true the new node is inserted
*/
template <class E> bool bst<E>::insertNode(bst *node, const E &e, bst *toInsert)
{
  if(e < node->key_)
  {
    if(node->left_ == nullptr)
    {
      node->left_ = toInsert;
      return true;
    }
    else
      insertNode(left_, e, toInsert);
  }
  else if (e > node->key_)
  {
    if(node->right_ == nullptr)
    {
      node->right_ = toInsert;
      return true;
    }
    else
      insertNode(node->right_, e, toInsert);
  }
  return false;
}

/*
  wrapper for insertNode
*/
template <class E> void bst<E>::insert(E e)
{
  bst* newNode = new bst(e);
  // if the node wasn't inserted because already present free it
  if(!insertNode(this, e, newNode))
    delete newNode;
  else
    size_++;
}

/*
  Use insertNode with a null node to detemine if the key is present
*/
template <class E> bool bst<E>::contain(const E &key) const
{
  return !insertNode(this, key, nullptr);
}

/*
  left first search to delete all pointers
*/
template <class E> bst<E>::~bst()
{
  if(left_ != nullptr)
  {
    left_->~bst();
    delete left_;
  }
  if(right_ != nullptr)
  {
    right_->~bst();
    delete right_;
  }
}

template<class E> size_t bst<E>::size() const
{
  return size_;
}

#endif /* bst_hpp */