//implementation of segment tree 

/* Segment tree is a pre-calculation data structure to complete queries in between ranges of
an array even if there occurs update in the array and query function is not inversible

n=total number of elements of array
*/

#include<bits/stdc++.h>
using namespace std;

/* tree[],prop[] should have size 4 times of arr[] 
hence Space Complexity O(4*n)
*/
const int n=100;
long long int arr[n+1];
long long int tree[4*n];
long long int prop[4*n];

struct // used a structure to compress the init, update and query function under segment tree
{
   //initializing segment tree in O(n) times
   void init(int node,int b,int e,int arr[],int tree[]) 
   {
      if(b==e)
      {
         tree[node]=arr[b];
         return;
      }
      int left=node<<1;
      int right=(node<<1)+1;
      int mid=(b+e)>>1;
      init(left,b,mid,arr,tree);
      init(right,mid+1,e,arr,tree);
      tree[node]=tree[left]+tree[right]; //function will be here
   }

   //update function to update a single node in O(log(n)) times
   void update(int node,int b,int e,int i,int newvalue,int tree[])
   {
      if(i>e||i<b)
      {
         return;
      }
      if(b>=i && e<=i)
      {
         tree[node]=newvalue;
      }
      int left=node<<1;
      int right=(node<<1)+1;
      int mid=(b+e)>>1;
      update(left,b,mid,i,newvalue,tree);
      update(right,mid+1,e,i,newvalue,tree);
      tree[node]=tree[left]+tree[right]; //function will be here 
   }

   // update function with lazy propagation from i to j with a newvalue in O(log(n)) times
   void lazy_update(int node,int b,int e,int i,int j,int newvalue,int tree[],int prop[])
   {
      if(i>e || j<b)
      {
         return;
      }
      if(b>=i && e<=j)
      {
         tree[node]+=(e-b+1)*newvalue; // function  will be here either +,-,*,/
         prop[node]+=newvalue;
         return;
      }

      int left=node<<1;
      int right=(node<<1)+1;
      int mid=(b+e)/2;
      lazy_update(left,b,mid,i,j,newvalue,tree,prop);
      lazy_update(right,mid+1,e,i,j,newvalue,tree,prop);
      tree[node]=tree[left]+tree[right]+(e-b+1)*prop[node]; // function  will be here either +,-,*,/
   }

   //query function
   int query(int node,int b,int e,int l,int r,int tree[],int prop[],int carry)
   {
      if(l>e||r<b)
      {
        return 0;//changeable according to function
      }
      if(b>=l && e<=r)
      {
         return tree[node]+carry*(e-b+1);
      }
      int left=node<<1;
      int right=(node<<1)+1;
      int mid=(b+e)>>1;
      int p1=query(left,b,mid,l,r,tree,prop,carry+prop[node]);
      int p2=query(right,mid+1,e,l,r,tree,prop,carry+prop[node]);
      return p1+p2;   //function will be here
   }


}segment_tree;