#include "dfile.h"

dfile::dfile(const std::string& fname, size_t bsize):filename_(fname), blockSize_(bsize)
{
	struct stat status;
	file_=open(filename_.data(), O_RDWR);	
	fstat(file_, &status);
	fileSize_=status.st_size;
	buffer_=mmap(0, fileSize_, PROT_READ|PROT_WRITE, MAP_SHARED, file_, 0);
}

dfile::~dfile()
{
	close(file_);
}

void* dfile::getData()
{
	return buffer_;
}
