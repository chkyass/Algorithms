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
    void insertNode(bst*, E );

  public:
    bst(E e);
    bool contain(E&);
    virtual void insert(E);
    virtual ~bst();
    void operator=(bst) = delete;
    bst(bst&) = delete;
};

template <class E> bst<E>::bst(E k): key_(k)
{}

/*
  If the element already exist does nothing
  Insert element at a leaf maintaining the invariant
*/
template <class E> void bst<E>::insert(E e)
{
  insertNode(this, e);
}


/*
  find the place where the node should be and insert it
  or does nothing if already present
*/
template <class E> void bst<E>::insertNode(bst *node, E e)
{
  if(e < node->key_)
  {
    if(node->left_ == nullptr)
      node->eft_ = new bst(e);
    else
      insertNode(left_, e);
  }
  else if (e > node->key_)
  {
    if(node->right_ == nullptr)
      node->right_.reset(new bst(e));
    else
      insertNode(node->right_, e);
  }
}

/*
  left first search to delete all pointers
*/
template <class E> bst<E>::~bst()
{
  if(left_ != nullptr)
  {
    left_.~bst();
    delete left_;
  }
  if(right_ != nullptr)
  {
    right_.~bst();
    delete right_;
  }
  
}

#endif /* bst_hpp */