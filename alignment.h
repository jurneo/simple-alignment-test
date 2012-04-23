#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include "alignmentmodel.h"

namespace processing {

/*! A class that provides the model for the alignment between image space point to the
 *  corresponding displacements in the world space (e.g. it could be a scanning motor of the mirror). 
 */
class Alignment
{
public:
    /* compute the alignment model for the given set of input image points and output laser points,
     * using least square methods. The valid model is currently, quadratic, and cubic.
     */
    static PairAlignmentResults computeModel(const ImagePoints& imgPts, const LaserPoints& laserPts,
                 AlignmentModel modelX = kQuadratic, AlignmentModel modelY = kQuadratic);
};

}

#endif // ALIGNMENT_H
