## Copyright (c) 2012, Cornell University
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted provided that the following conditions are met:
##
##     * Redistributions of source code must retain the above copyright notice,
##       this list of conditions and the following disclaimer.
##     * Redistributions in binary form must reproduce the above copyright
##       notice, this list of conditions and the following disclaimer in the
##       documentation and/or other materials provided with the distribution.
##     * Neither the name of Hiredispp nor the names of its contributors may be
##       used to endorse or promote products derived from this software without
##       specific prior written permission.
##
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
## AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
## IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
## ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
## LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
## CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
## SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
## INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
## CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
## ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
## POSSIBILITY OF SUCH DAMAGE.

ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}
AM_CXXFLAGS = $(COVERAGE_CXXFLAGS)

.PHONY: coverage

################################################################################
############################## Hyperspace Hashing ##############################
################################################################################

#################################### Library ###################################

libhiredispp_includedir = $(includedir)/
libhiredispp_include_HEADERS = \
			hiredispp.h \
			hiredispp-impl.h

##################################### Tests ####################################

################################################################################
################################### Coverage ###################################
################################################################################

if ENABLE_COVERAGE
coverage: coverage.dat
	mkdir -p coverage
	genhtml --function-coverage --branch-coverage --demangle-cpp --output coverage $(abs_top_builddir)/coverage.dat

coverage.dat: check
	lcov --directory $(abs_top_builddir) --compat-libtool --capture --output $(abs_top_builddir)/coverage.dat
	lcov --extract $(abs_top_builddir)/coverage.dat $(abs_top_builddir)/'*' --output $(abs_top_builddir)/coverage.dat

clean-coverage:
	rm -f coverage.dat
	rm -rf coverage/
	find $(abs_top_builddir) -type f -iname '*.gcda' -delete
	find $(abs_top_builddir) -type f -iname '*.gcno' -delete

clean-local: clean-coverage
else
coverage:
	@echo Coverage not configured.
endif
