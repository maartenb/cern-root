// Author: Enrico Guiraud, Danilo Piparo CERN  09/2018

/*************************************************************************
 * Copyright (C) 1995-2018, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#include "ROOT/RDF/RCustomColumnBase.hxx"
#include "ROOT/RDF/RLoopManager.hxx"
#include "ROOT/RStringView.hxx"
#include "RtypesCore.h" // Long64_t

#include <string>
#include <vector>

using ROOT::Detail::RDF::RCustomColumnBase;
using ROOT::Detail::RDF::RLoopManager;
namespace RDFInternal = ROOT::Internal::RDF;

unsigned int RCustomColumnBase::GetNextID()
{
   static unsigned int id = 0U;
   ++id;
   return id;
}

RCustomColumnBase::RCustomColumnBase(RLoopManager *lm, std::string_view name, const unsigned int nSlots,
                                     const bool isDSColumn, const RDFInternal::RBookedCustomColumns &customColumns)
   : fLoopManager(lm), fName(name), fNSlots(nSlots), fIsDataSourceColumn(isDSColumn), fLastCheckedEntry(fNSlots, -1),
     fCustomColumns(customColumns), fIsInitialized(nSlots, false)
{
}

// pin vtable. Work around cling JIT issue.
RCustomColumnBase::~RCustomColumnBase() {}

std::string RCustomColumnBase::GetName() const
{
   return fName;
}

void RCustomColumnBase::InitNode()
{
}
