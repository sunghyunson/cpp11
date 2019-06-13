#include <iostream>

using namespace std;

// TODO:  What about the messy loop
for (size_t i = 0; i < expanded_panels.size(); ++i) {
	Panel* panel = expaned_panels[i].get();
	if (center_x <= panel->cur_panel_center() || i == expaned_panels.size() - 1) {
		if (panel != fixed_panel) {
			// If it has, then we reorder the panels.
			ref_ptr<Panel> ref = expaned_panels[fixed_index];
			expaned_panels.erase(expanded_panels.begin() + fixed_index);
			if (i < expanded_panels.size()) {
				expanded_panels.insert(expanded_panels.begin() + i, ref);
			} else {
				expanded_panels.push_back(ref);
			}
			break;
		}
	}
}

for (size_t i = 0; i < expanded_panels.size(); ++i) {
	Panel* panel = expaned_panels[i].get();
	// TODO : i == expaned_panesl.size() - 1 is always true
	if (center_x <= panel->cur_panel_center() || i == expaned_panels.size() - 1) {
		if (panel != fixed_panel) {
			// If it has, then we reorder the panels.
			ref_ptr<Panel> ref = expaned_panels[fixed_index];
			expaned_panels.erase(expaned_panels.begin() + fixed_index);
			expaned_panels.insert(expaned_panels.begin() + i, ref);
		}
		break;
	}
}

for (size_t i = 0; i < expanded_panels.size(); ++i) {
	Panel* panel = expaned_panels[i].get();
	// TODO : i == expaned_panesl.size() - 1 is always true
	if (center_x <= panel->cur_panel_center() || i == expaned_panels.size() - 1) {
		break;
	}
}
// Fix this code - panel is the panel found above.
if (panel != fixed_panel) {
	// If it has, then we reorder the panels.
	ref_ptr<Panel> ref = expaned_panels[fixed_index];
	expaned_panels.erase(expaned_panels.begin() + fixed_index);
	expaned_panels.insert(expaned_panels.begin() + i, ref);
}

auto p = find_if(begin(expaned_panels), end(expaned_panels)),
	[&](const ref_ptr<Panel>& e)
	{
		return center_x <= e->cur_panel_center();
	});
// Fix this code - panel is the panel found above.
if (panel != fixed_panel) {
	// If it has, then we reorder the panels.
	ref_ptr<Panel> ref = expaned_panels[fixed_index];
	expaned_panels.erase(expaned_panels.begin() + fixed_index);
	expaned_panels.insert(expaned_panels.begin() + i, ref);
}



auto p = find_if(begin(expaned_panels), end(expaned_panels)),
	[&](const ref_ptr<Panel>& e)
	{
		return center_x <= e->cur_panel_center();
	});
// Fix this code - panel is the panel found above.
if (panel != fixed_panel) {
	// If it has, then we reorder the panels.
	auto f = begin(expanded_panels) + fixed_index;
	rotate(p, f, f + 1);
}
