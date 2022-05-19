import pumapy as puma
import numpy as np
import time

size = (100, 100, 100)
r = 5
ip, oop = 90, 20

ws_fibers = puma.generate_random_fibers(size, r, porosity=0.89, phi=oop, theta=ip, length=400)

cond_map = puma.IsotropicConductivityMap()
cond_map.add_material((0, 1), 0.0257) # conductivity of the air
cond_map.add_material((2, ws_fibers.max()), 12) # conductivity of carbon fibres

start_time = time.time()
k_eff_z = puma.compute_thermal_conductivity(ws_fibers, cond_map, 'z', 's')[0]
duration = time.time() - start_time

print(duration)