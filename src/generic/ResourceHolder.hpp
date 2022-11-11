#pragma once

#include<map>
#include<string>

/**
 * @brief Loads and stores resources.
 * @ingroup generic
 */
	template<class Resource, class Identifier>
class ResourceHolder {
	public:
		/// Call loadFromFile on Resource.
		void load(Identifier id, std::string const& filename);

		Resource const&	get(Identifier id) const;

	private:
		std::map<Identifier, Resource>	_resources;
};

#include "ResourceHolder.inl"
