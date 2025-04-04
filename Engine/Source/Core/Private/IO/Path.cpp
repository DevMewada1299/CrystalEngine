
#include "IO/Path.h"


namespace CE::IO
{

	Path::Path() : impl()
	{
		
	}

	Path::~Path()
	{

	}

    bool Path::IsSubDirectory(Path path, Path root)
    {
		for (auto r = root.begin(), p = path.begin(); r != root.end(); ++r, ++p)
		{
			if (p == path.end() || *p != *r)
			{
				return false;
			}
		}
		return true;
    }

	bool Path::PathStringContains(const Path& fullPath, const Path& subString)
	{
		bool firstMatchFound = false;
		for (auto f = fullPath.begin(), s = subString.begin(); f != fullPath.end(); ++f)
		{
			if (*s == *f)
			{
				if (!firstMatchFound)
					s = subString.begin();
				++s;
				firstMatchFound = true;
			}
			else
			{
				firstMatchFound = false;
			}

			if (s == subString.end())
				return true;
		}

		return false;
	}

    void Path::IterateChildren(std::function<void(const IO::Path& path)> func)
	{
		for (const auto& iter : fs::directory_iterator(impl))
		{
			func(iter.path());
		}
	}

	void Path::RecursivelyIterateChildren(std::function<void(const IO::Path& path)> func)
	{
		for (const auto& iter : fs::recursive_directory_iterator(impl))
		{
			func(iter.path());
		}
	}

	void Path::EvaluateVirtualPath()
	{
		
	}

} // namespace CE::IO

