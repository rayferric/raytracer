#pragma once

#include "pch.hpp"

#include "core/material.hpp"
#include "image/texture.hpp"
#include "math/vec2.hpp"
#include "math/vec3.hpp"
#include "scene/camera.hpp"
#include "scene/entity.hpp"

namespace core {

class renderer {
public:
	math::uvec2 resolution;
	uint32_t thread_count;
	uint32_t sample_count;
	uint8_t bounce_count;
	std::shared_ptr<scene::entity> root;
	std::shared_ptr<scene::camera> camera;
	std::shared_ptr<image::texture> environment;

	renderer();

	void load_gltf(
			const std::filesystem::path &path);

	void render(const std::filesystem::path &path) const;

private:
	struct trace_result {
		bool hit;
		std::shared_ptr<core::material> material;

		math::fvec3 position;
		math::fvec2 tex_coord;
		math::fvec3 normal;
		math::fvec3 tangent;

		math::fvec3 get_normal() const;
	};

	math::fvec3 integrate(uint8_t bounce, const geometry::ray &ray) const;

	trace_result trace(const geometry::ray &ray) const;
};

}
