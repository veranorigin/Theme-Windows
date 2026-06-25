/*
  contributers:Su Yu Ning
  date:2026-6-25
*/
//a base class
#pragma once

class RegistryChange {
	/*
	  a base class for rigistry change,which is a must in this project.
	 */
public:
	RegistryChange()=default;
	virtual ~RegistryChange()=default;
	virtual int do_the_change()=0;
	virtual int reset()=0;
};
