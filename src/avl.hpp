#ifndef avl_h
#define avl_h

#include "bst.hpp"

template <class K>
struct avl_node{
  avl_node *left_;
  avl_node *right_;
  K key_;
  int height_;
  avl_node(K k):left_(nullptr), right_(nullptr), key_(k), height_(0){}
};

template <class K>
class avl: public bst<K, avl_node<K> >
{
  using bst<K, avl_node<K> >::root_;
  using bst<K, avl_node<K> >::size_;

  private:
    avl_node<K>* left_rotate(avl_node<K>*);
    avl_node<K>* right_rotate(avl_node<K>*);
    int getHeight(avl_node<K>*);
    avl_node<K>* balance(avl_node<K>*);
    size_t get_heavier_child(avl_node<K>*);
    void update_height(avl_node<K>*);

  public:
    avl(K);
    avl_node<K>* insertNode(avl_node<K>*, const K&, bool &exist, bool);
    bool contain(const K&);
    void insert(const K&);
    int height();
};

template <class K> avl<K>::avl(K e):bst<K, avl_node<K> >(e)
{
  root_->height_ = 0;
}

/*
  treat absent node as they have height = -1 
*/
template <class K> int avl<K>::getHeight(avl_node<K> *node)
{
 return node == nullptr ? -1 : node->height_;
}

/*
  height = max(left_height, right_left) + 1
*/
template <class K> void avl<K>::update_height(avl_node<K> *node)
{
  int l_h = getHeight(node->left_);
  int r_h = getHeight(node->right_);
  node->height_ = (l_h > r_h ? l_h : r_h)  + 1;
}

/*
  left rotate the node. Take the node make his right child his parent
  and make the right->left child the new right child.
*/
template<class K> avl_node<K>* avl<K>::left_rotate(avl_node<K> *node)
{
  avl_node<K> *new_root = node->right_;
  node->right_ = node->right_->left_;
  new_root->left_ = node;
  
  update_height(node);
  update_height(new_root);  
  return new_root;
}

/*
  right rotate the node. Take the node make his left child his parent
  and make his left->right child the new left child
*/
template<class K> avl_node<K>* avl<K>::right_rotate(avl_node<K> *node)
{
  avl_node<K> *new_root = node->left_;
  node->left_ = node->left_->right_;
  new_root->right_ = node;

  update_height(node);
  update_height(new_root);
  return new_root;
}

/*
  balance tree after an insertion
*/
template <class K> avl_node<K>* avl<K>::balance(avl_node<K> *node)
{
  int diff = getHeight(node->left_) - getHeight(node->right_);

  // check if the tree is balanced
  if(diff == 1 || diff == -1 || diff == 0) 
  {
    update_height(node);
    return node;
  }

  //left case
  if(getHeight(node->left_) > getHeight(node->right_))
  {
    //left-right case
    if(getHeight(node->left_->right_) > getHeight(node->left_->left_))
      node->left_ = left_rotate(node->left_);
    return right_rotate(node);
  }
  //right case
  else
  {
    //right-left case
    if(getHeight(node->right_->left_) > getHeight(node->right_->right_))
      node->right_ = right_rotate(node->right_);
    return left_rotate(node);
  }
}

/*
  insert a node.
  exist contain true if the key is already present
  dry_mode used to check if a key is present
*/
template <class K> avl_node<K>* avl<K>::insertNode(avl_node<K>* node, const K& k, bool& exist, bool dry_mode)
{
  if( node->key_ == k)
  {
    exist = true;    
    return node;
  }
  
  // insert the node at the right place
  avl_node<K> **next = k < node->key_ ? &(node->left_) : &(node->right_);
  if(*next == nullptr && !dry_mode)
    *next = new avl_node<K>(k);
  else
    *next = insertNode(*next, k, exist, dry_mode);

  // balance the tree if needed
  return balance(node);
}

template <class K> bool avl<K>::contain(const K& key)
{
  bool exist = false;
  insertNode(root_, key, exist, true);

  return exist;
}

template <class K> void avl<K>::insert(const K& key)
{
  bool exist = false;
  root_ = insertNode(root_, key, exist, false);
  if(!exist)
    size_++;
}

template <class K> int avl<K>::height()
{
  return root_->height_;
}

#endif