/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ADDMATRIX_H__
#define __MayaDM_ADDMATRIX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class AddMatrix : public DependNode
{
public:
public:
	AddMatrix():DependNode(){}
	AddMatrix(FILE* file,const std::string& name,const std::string& parent="",bool create=true)
		:DependNode(file, name, parent, "addMatrix", create){}
	virtual ~AddMatrix(){}
	void setMatrixIn(size_t i_i,const matrix& i_)
	{
		if(i_ == identity) return;
		fprintf(mFile,"\tsetAttr \".i[%i]\" -type \"matrix\" ",i_i);
		i_.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMatrixIn(size_t i_start,size_t i_end,matrix* i_)
	{
		fprintf(mFile,"\tsetAttr \".i[%i:%i]\" ", i_start,i_end);
		size_t size = (i_end-i_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			i_[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");

	}
	void startMatrixIn(size_t i_start,size_t i_end)const
	{
		fprintf(mFile,"\tsetAttr \".i[%i:%i]\"",i_start,i_end);
		fprintf(mFile," -type \"matrix\" ");

	}
	void appendMatrixIn(const matrix& i)const
	{
		fprintf(mFile,"\n");
		i.write(mFile);

	}
	void endMatrixIn()const
	{
		fprintf(mFile,";\n");

	}
	void getMatrixIn(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i]\"",mName.c_str(),i_i);

	}
	void getMatrixSum()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
protected:
	AddMatrix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool create=true)
		:DependNode(file, name, parent, nodeType, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ADDMATRIX_H__