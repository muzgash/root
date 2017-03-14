// @(#)root/mpi / Author: Gerardo Gutierrez, muzgash@gmail.com
#ifndef ROOT_Mpi_TCartCommunicator
#define ROOT_Mpi_TCartCommunicator

#include<Mpi/TCommunicator.h>

namespace ROOT {

   namespace Mpi {

      class TCartCommunicator: public TCommunicator {
      public:

         TCartCommunicator();

         TCartCommunicator(const TCartCommunicator &data);

         TCartCommunicator(const MPI_Comm &comm);

         TCartCommunicator &operator=(const TCartCommunicator &comm)
         {
            fComm = comm.fComm;
            return *this;
         }

         TCartCommunicator &operator=(const MPI_Comm &comm)
         {
            fComm = comm;
            return *this;
         }

         inline operator MPI_Comm() const
         {
            return fComm;
         }

         TCartCommunicator Dup() const;

         virtual TCartCommunicator &Clone() const;

         virtual TCartCommunicator Create(Int_t ndims, const Int_t dims[], const Int_t periods[], Int_t reorder) const;

         Int_t* Coords(Int_t rank, Int_t maxdims) const;
         
         void Get(Int_t maxdims, Int_t dims[], Int_t periods[], Int_t coords[]) const;
         
         Int_t Map(Int_t ndims, const Int_t dims[], const Int_t periods[]) const;
         
         Int_t Rank(Int_t coords[]) const;
         
         void Shift(Int_t direction, Int_t disp, Int_t *rank_source, Int_t *rank_dest) const;

         TCartCommunicator Sub(const Int_t remain_dims[]) const;
         
         Int_t DimGet() const;

         ClassDef(TCartCommunicator, 3)
      };
   }
}

#endif
