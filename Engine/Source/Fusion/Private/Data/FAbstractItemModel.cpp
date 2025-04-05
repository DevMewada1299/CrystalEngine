#include "Fusion.h"

namespace CE
{
	SIZE_T FModelIndex::GetHash() const
	{
		SIZE_T dataHash = 0;
		if (data.HasValue())
		{
			dataHash = data.GetHash();
		}
        return GetCombinedHashes({ (SIZE_T)GetRow(), (SIZE_T)GetColumn(), dataHash });
	}

	bool FModelIndex::operator==(const FModelIndex& other) const
	{
        return GetHash() == other.GetHash();
	}

	bool FModelIndex::operator!=(const FModelIndex& other) const
	{
        return !operator==(other);
	}

    FAbstractItemModel::FAbstractItemModel()
    {
        
    }

    FAbstractItemModel::~FAbstractItemModel()
    {

    }

    FModelIndex FAbstractItemModel::CreateIndex(u32 row, u32 col, const Variant& data)
    {
        FModelIndex index;
        index.row = row;
        index.col = col;
        index.data = data;
        index.model = this;

        return index;
    }

} // namespace CE

