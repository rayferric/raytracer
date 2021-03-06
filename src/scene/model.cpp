#include "scene/model.hpp"

#include "math/vec3.hpp"

using namespace geometry;
using namespace math;

namespace scene {

bool model::intersection::has_hit() const {
	return distance >= 0;
}

void model::recalculate_aabb() {
	aabb.clear();
	for (auto &surface : surfaces) {
		aabb.add(surface.mesh->aabb);
	}
}

model::intersection model::intersect(
		const ray &ray) const {
	scene::transform transform = get_entity()->
			get_global_transform();
	scene::transform inv_transform
			= transform.inverse();

	auto view_ray = ray.transform(inv_transform);

	if (!aabb.intersect(view_ray).has_hit())
		return {};

	core::mesh::intersection nearest_hit;
	const surface *hit_surface;

	for (const auto &surface : surfaces) {
		const auto &mesh = surface.mesh;

		auto hit = mesh->intersect(view_ray);

		if (!hit.has_hit())
			continue;
	
		if (hit.distance < nearest_hit.distance
				|| !nearest_hit.has_hit()) {
			nearest_hit = hit;
			hit_surface = &surface;
		}
	}

	if (!nearest_hit.has_hit())
		return {};

	// To provide correct distance for scaled models,
	// we transform local hit position to world space
	// and compute distance to ray origin
	// fvec3 hit_pos = view_ray.origin + view_ray.get_dir() * nearest_hit.distance;
	// nearest_hit.distance = distance(ray.origin, transform * hit_pos);

	fvec3 hit_vec = view_ray.get_dir() * nearest_hit.distance;
	nearest_hit.distance = length(transform.basis * hit_vec);

	return {
		nearest_hit.distance,
		transform,
		hit_surface,
		nearest_hit.index,
		nearest_hit.barycentric
	};
}

};
