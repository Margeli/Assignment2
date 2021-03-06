#include "GuiImage.h"
#include "j1Gui.h"
#include "j1UI_Elem.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "Brofiler\Brofiler.h"

GuiImage::GuiImage(Alignment alignment): j1UI_Elem(UIType::IMAGE, Alignment::NO_ALIGN)
{
	align = alignment;
}

GuiImage::~GuiImage()
{}

bool GuiImage::Start() 
{
	if (tex == nullptr) { tex = App->gui->GetAtlas(); }
	
	return true;
}

bool GuiImage::CleanUp()
{
	if(tex != nullptr)
	App->tex->UnLoad(tex);
	to_delete = true;
	return true;
}

bool GuiImage::Update(float dt) 
{
	BROFILER_CATEGORY("GuiImage_Update", Profiler::Color::OrangeRed);

	UpdateAlignment();
	if (draw) { App->render->Blit(tex, position.x + displacement.x, position.y + displacement.y, &rect); }
		
	return true;
}

void GuiImage::Drag(iPoint displace)
{
	displacement.x += displace.x;
	displacement.y += displace.y;
	
}