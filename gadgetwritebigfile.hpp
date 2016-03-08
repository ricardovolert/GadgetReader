#ifndef GADGETWRITE_BIGFILE_H
#define GADGETWRITE_BIGFILE_H

#include <valarray>
#include <string>
#include <stdint.h>
#include "gadgetwriter.hpp"
#include "gadgetheader.h"
#include "bigfile.h"

namespace GadgetWriter {
  /** Main class for reading Gadget BigFile snapshots. */
  class GWriteBigSnap : GWriteBaseSnap{
          public:
                  /** Base constructor. If you want an HDF5 snapshot, pass a filename ending in .hdf5 */
                  GWriteBigSnap(std::string snap_filename, std::valarray<int64_t> npart_in,int num_files=1, bool debug=true);
                  int64_t WriteBlocks(std::string& BlockName, int type, void *data, uint64_t np_write, uint64_t begin, const char * dtype, int items_per_particle);
                  //Note the value of npart used is that from npart_in, not the header.
                  int WriteHeaders(gadget_header head);
                  ~GWriteBigSnap();
          private:
                  BigFile bf;
  };

}

#endif
