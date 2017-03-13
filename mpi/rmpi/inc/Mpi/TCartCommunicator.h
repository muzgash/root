// @(#)root/mpi / Author: Omar.Zapata@cern.ch 2017 http://oproject.org
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

         virtual Int_t GetRemoteSize() const;

         virtual TGroup GetRemoteGroup() const;

         TCartCommunicator Dup() const;

         virtual TCartCommunicator &Clone() const;

         virtual TCartCommunicator Merge(Int_t high);

         virtual TCartCommunicator Create(const TGroup &group) const;

         virtual TCartCommunicator Split(Int_t color, Int_t key) const;

         ClassDef(TCartCommunicator, 3)
      };
   }
}

#endif
