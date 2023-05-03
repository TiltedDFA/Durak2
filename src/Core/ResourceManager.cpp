#include "headers/ResourceManager.hpp"
#include <assert.h>

Resource_Manager::Resource_Manager() 
{
	DBG_CTOR("Resource Manager",this);
	assert(m_s_instance == nullptr);
	m_s_instance = this;
}
Resource_Manager::~Resource_Manager()
{
	DBG_DTOR("Resource Manager",this);
}
sf::Texture& Resource_Manager::get_texture(const std::string& name) 
{
	auto& texture_map = m_s_instance->m_textures;
	auto keyValuePair = texture_map.find(name);

	if (keyValuePair != texture_map.end())
	{
		return keyValuePair->second;
	}
	else {
		auto& texture = texture_map[name];
		if (!texture.loadFromFile(name))
		{
			throw std::runtime_error("FAILED TO LOAD TEXTURE");
		}
		return texture;
	}
}
sf::Font& Resource_Manager::get_font(const std::string& font_name) 
{
	auto& font_map = m_s_instance->m_fonts;
	auto keyValuePair = font_map.find(font_name);
	if (keyValuePair != font_map.end()) {
		DBG_MSG_AT("Font loaded from memory",Resource_Manager::m_s_instance);
		return keyValuePair->second;
	}
	else {
		auto& font = font_map[font_name];
		if (!font.loadFromFile(font_name))
		{
			throw std::runtime_error("FAILED TO LOAD FONT");
		}
		DBG_MSG_AT("Font loaded from file",Resource_Manager::m_s_instance);
		return font;
	}
}