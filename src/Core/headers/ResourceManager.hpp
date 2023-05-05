#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include "Debug.hpp"
constexpr std::string_view FONT_PATH{"../assets/Retron2000.ttf"};
class Resource_Manager
{	
public:
	Resource_Manager();
	~Resource_Manager();
	Resource_Manager(const Resource_Manager& other) = delete;//deleting copy construct
	void operator=(const Resource_Manager& other) = delete;
	Resource_Manager(const Resource_Manager&& other) = delete;//deleting move construct
	void operator=(Resource_Manager&& other) = delete;
	static sf::Texture& get_texture(const std::string& texture_name);
	static sf::Font& get_font(const std::string& font_name);
private:
	inline static Resource_Manager* m_s_instance = nullptr;
	std::map<std::string, sf::Texture> m_textures;
	std::map<std::string, sf::Font> m_fonts;	
};
#endif