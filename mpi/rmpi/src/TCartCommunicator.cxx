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
TCartCommunicator TCartCommunicator::Merge(Int_t high)
{
   MPI_Comm ncomm;
   MPI_Intercomm_merge(fComm, high, &ncomm);
   return ncomm;
}

//______________________________________________________________________________
Int_t TCartCommunicator::GetRemoteSize() const
{
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
TCartCommunicator TCartCommunicator::Create(int ndims, const int dims[], const int periods[], int reorder) const
{
   MPI_Comm ncomm;
   
   MPI_Comm_create(fComm, group, &ncomm);
   ROOT_MPI_CHECK_COMM(ncomm);
   return  ncomm;
}

int* TCartCommunicator::Coords(int rank, int maxdims, int coords[]) const
{}

// Retrieves Cartesian topology information associated with a communicator.
void TCartCommunicator::Get(int maxdims, int dims[], int periods[], int coords[]) const
{}

//Maps process to Cartesian topology information.
int TCartCommunicator::Map(int ndims, const int dims[], const int periods[]) const
{}

//Determines process rank in communicator given Cartesian location.
int TCartCommunicator::Rank(int coords[]) const
{}

//Returns the shifted source and destination ranks, given a shift direction and amount.
int TCartCommunicator::Shift(int direction, int disp, int *rank_source, int *rank_dest) const
{}

//Partitions a communicator into subgroups, which form lower-dimensional Cartesian subgrids.
TCartCommunicator TCartCommunicator::Sub(const int remain_dims[]) const
{}

//Retrieves Cartesian topology information associated with a communicator.
int TCartCommunicator::DimGet(int *ndims) const
{}
