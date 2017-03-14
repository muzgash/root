#include<Mpi/TCartCommunicator.h>
#include<Mpi/TCartCommunicator.h>
using namespace ROOT::Mpi;

//______________________________________________________________________________
TCartCommunicator::TCartCommunicator(): TCommunicator() {}

//______________________________________________________________________________
TCartCommunicator::TCartCommunicator(const TCartCommunicator &comm): TCommunicator(comm) {}

//______________________________________________________________________________
TCartCommunicator::TCartCommunicator(const MPI_Comm &comm): TCommunicator(comm) {}

//______________________________________________________________________________
TCartCommunicator &TCartCommunicator::Clone() const
{
   MPI_Comm dupcomm;
   MPI_Comm_dup(fComm, &dupcomm);
   TCartCommunicator *ccomm = new TCartCommunicator(dupcomm);
   return  *ccomm;
}

//______________________________________________________________________________
TCartCommunicator TCartCommunicator::Dup() const
{
   MPI_Comm dupcomm;
   MPI_Comm_dup(fComm, &dupcomm);
   ROOT_MPI_CHECK_COMM(dupcomm);
   return  dupcomm;
}

//______________________________________________________________________________
TCartCommunicator TCartCommunicator::Create(Int_t ndims, const Int_t dims[], const Int_t periods[], Int_t reorder) const
{
   MPI_Comm ncomm;
   MPI_Cart_create(fComm, ndims, dims, periods, reorder, &ncomm);
   ROOT_MPI_CHECK_COMM(ncomm);
   return  ncomm;
}

Int_t* TCartCommunicator::Coords(Int_t rank, Int_t maxdims) const
{
    Int_t *coords=new Int_t[maxdims];
    MPI_Cart_coords(fComm, rank,maxdims,coords);
    return coords;
}

// Retrieves Cartesian topology information associated with a communicator.
void TCartCommunicator::Get(Int_t maxdims, Int_t dims[], Int_t periods[], Int_t coords[]) const
{
    MPI_Cart_get(fComm, maxdims, dims, periods, coords);
}

//Maps process to Cartesian topology information.
Int_t TCartCommunicator::Map(Int_t ndims, const Int_t dims[], const Int_t periods[]) const
{
    Int_t nrank;
    MPI_Cart_map(fComm,ndims,dims,periods,&nrank);
    return nrank;
}

//Determines process rank in communicator given Cartesian location.
Int_t TCartCommunicator::Rank(Int_t coords[]) const
{
    Int_t rank;
    MPI_Cart_rank(fComm,coords,&rank);
    return rank;
}

//Returns the shifted source and destination ranks, given a shift direction and amount.
void TCartCommunicator::Shift(Int_t direction, Int_t disp, Int_t *rank_source, Int_t *rank_dest) const
{
    MPI_Cart_shift(fComm, direction, disp, rank_source, rank_dest);
}

//Partitions a communicator into subgroups, which form lower-dimensional Cartesian subgrids.
TCartCommunicator TCartCommunicator::Sub(const Int_t remain_dims[]) const
{
    MPI_Comm ncomm;
    MPI_Cart_sub(fComm, remain_dims,&ncomm);
    return ncomm;
}

//Retrieves Cartesian topology information associated with a communicator.
Int_t TCartCommunicator::DimGet() const
{
    Int_t ndims;
    MPI_Cartdim_get(fComm,&ndims);
    return ndims;
}
