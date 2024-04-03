# x86-to-C Interface Programming Project
Joshua Emmanuel G. Tipon <br />
LBYARCH2 XX22 - Hiroki Asaba
## Average Execution Time Of Each Vector Size: 2<sup>20</sup>, 2<sup>24</sup>, and 2<sup>30</sup>
30 runs of the program were executed to get the average execution time of each kernel of each size and each version.

### Debug Version
| Vector Size | Assembly Kernel | C Kernel |
| --- | --- | --- |
| **2<sup>20</sup>** | 0.001300 | 0.002567 |
| **2<sup>24</sup>** | 0.020233 | 0.044133 |
| **2<sup>30</sup>** | 1.332500 | 2.793433 |

### Release Version
| Vector Size | Assembly Kernel | C Kernel |
| --- | --- | --- |
| **2<sup>20</sup>** | 0.001267 | 0.001367 |
| **2<sup>24</sup>** | 0.020000 | 0.020033 |
| **2<sup>30</sup>** | 1.353367 | 1.322067 |



## Comparative Execution Time and Short Analysis of the Performance of the Kernels
Based on the results gatheres through the executions, we were able to learn that the Assembly Kernel were generally faster than the C Kernel in both debug and release versions, with the release version of the vector size of 2<sup>30</sup> being an outlier where the C Kernel was faster than the Assembly Kernel by 0.0313 seconds.

## Screenshot of the Program Output With The Correctness Check (C).
### Debug Versions
Debug Version: 2<sup>20</sup>
![debug 2<sup>20</sup>](./debug1.png)
Debug Version: 2<sup>24</sup>
![debug 2<sup>24</sup>](./debug2.png)
Debug Version: 2<sup>30</sup>
![debug 2<sup>30</sup>](./debug3.png)

# Release Versions
Release Version: 2<sup>20</sup>
![release 2<sup>20</sup>](./release1.png)
Release Version: 2<sup>24</sup>
![release 2<sup>24</sup>](./release2.png)
Release Version: 2<sup>30</sup>
![release 2<sup>30</sup>](./release3.png)
