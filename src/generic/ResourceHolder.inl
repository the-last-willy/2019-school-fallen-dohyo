#include<stdexcept>
	
	template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(
	Identifier id, 
	std::string const& fileName
) {
	auto& resource = _resources[id];
	resource.loadFromFile(fileName);
}

	template<typename Resource, typename Identifier>
Resource const& ResourceHolder<Resource, Identifier>::get(Identifier id) const {
	auto resource = _resources.find(id);
	#ifdef DEBUG
	if(resource == _resources.end()) throw std::runtime_error(
		"ResourceHolder::get - Missing resource."
	);
	#endif
	return resource->second;
}
