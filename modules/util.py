import numpy as np



def make_coordinate_grid(spatial_size:tuple(int,int),type)->np.ndarray:
    """[summary]

    Args:
        spatial_size ([type]): [description]
        type ([type]): [description]
    """
    h,w = spatial_size
    x=np.arange(w).astype(type)
    y = np.arange(h)
    x.reshape(-1,1)
    