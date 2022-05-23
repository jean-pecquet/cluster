import pumapy as puma

ws_fibers = puma.generate_random_fibers((100, 100, 100), 5, None, 0.89, 20, 90, 400, segmented=True)

cond_map = puma.IsotropicConductivityMap()
cond_map.add_material((0, 0), 0.0257) # conductivity of the air
cond_map.add_material((1, ws_fibers.max()), 12) # conductivity of carbon fibres

k_eff_z, T_z, q_z = puma.compute_thermal_conductivity(ws_fibers, cond_map, 'z', 's', tolerance=1e-3, solver_type='cg')
