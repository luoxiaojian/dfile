#ifndef _DFILE_H_
#define _DFILE_H_

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string>
#include <sys/mman.h>
#include <sys/stat.h>

class dfile {
	public:
		dfile(const std::string& fname, size_t bsize);
		~dfile();
		void *getData();

	private:
		std::string filename_;
		size_t fileSize_;
		size_t blockSize_;
		void *buffer_;
		int file_;

		dfile(const dfile&);
		void operator=(const dfile&);
};

#endif
