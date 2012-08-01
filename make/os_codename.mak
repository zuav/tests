# -*- Makefile -*-

os_codename = $(strip $(shell lsb_release -c | awk '{print $$2}'))


ifeq ($(os_codename),$(findstring $(os_codename),squeeze precise Carbon))

dist_supported=true

else

dist_supported=false

endif


ifeq ($(strip $(os_codename)),squeeze)

os_distr = squeeze

endif

ifeq ($(os_codename), precise)

os_distr = precise

endif

ifeq ($(os_codename), Carbon)

os_distr = Carbon

endif



all:
	@echo `lsb_release -c | awk '{print $$2}'`
	@echo OS codename is: $(os_codename).
	@echo Distr is supported: $(dist_supported).
	@echo $(filter $(os_codename),squeeze precise Carbon).
	@echo $(findstring $(os_codename),squeeze precise Carbon).
	@echo OS distr: $(os_distr).
