#include "compute_volume.h"

double
ComputeVolume::operator()(double x, double y, double z)
{
        return x * y * z;
}
