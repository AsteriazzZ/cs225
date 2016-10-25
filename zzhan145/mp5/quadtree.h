/**
 * @file quadtree.h
 * Quadtree class definition.
 * @date Spring 2008
 */

#ifndef QUADTREE_H
#define QUADTREE_H

#include "png.h"

/**
 * A tree structure that is used to compress PNG images.
 */
class Quadtree
{
  public:
    Quadtree();
    Quadtree(PNG &source, int resolution);
    Quadtree(const Quadtree &other);
    ~Quadtree();
    Quadtree &operator=(Quadtree const &other);
    
    void buildTree(PNG const &source, int resolution);
    RGBAPixel getPixel(int x, int y) const;
    PNG decompress() const;
    void clockwiseRotate();
    void prune(int tolerance);
    int pruneSize(int tolerance) const;
    int idealPrune(int numLeaves) const;
    
  private:
    /**
     * A simple class representing a single node of a Quadtree.
     * You may want to add to this class; in particular, it could
     * probably use a constructor or two...
     */
    class QuadtreeNode
    {
      public:
        QuadtreeNode* nwChild; /**< pointer to northwest child */
        QuadtreeNode* neChild; /**< pointer to northeast child */
        QuadtreeNode* swChild; /**< pointer to southwest child */
        QuadtreeNode* seChild; /**< pointer to southeast child */

        RGBAPixel element; /**< the pixel stored as this node's "data" */
    };

    QuadtreeNode* root; /**< pointer to root of quadtree */
    
    int resolution;
    
    void clear(QuadtreeNode *&curNode);
    void copy(QuadtreeNode *& cop, QuadtreeNode * const & org);
    void buildTree(QuadtreeNode *&curNode, PNG const &source, int x, int y, int resolution);
    RGBAPixel getPixel(QuadtreeNode *curNode, int x, int y, int resolution)const;
    void decompress(QuadtreeNode *curNode, PNG &source, int x, int y, int resolution)const;
    void clockwiseRotate(QuadtreeNode *curNode);
    void prune(int tolerance, QuadtreeNode *curNode);
    bool checkPrune(QuadtreeNode *root, QuadtreeNode *curNode, int resolution) const;
    int pruneSize(QuadtreeNode *curNode, int resolution) const;
    int search(int numLeaves, int low, int high)const;


/**** Functions for testing/grading                      ****/
/**** Do not remove this line or copy its contents here! ****/
#include "quadtree_given.h"
};

#endif
