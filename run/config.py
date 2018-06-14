#!/besfs/groups/higgs/users/chenlj/software/anaconda3/bin/python

import subprocess
import time
import argparse

Noise_file_name = [
    "CHIPA1_180322145948.df"
    ,"CHIPA2_180322145430.df"
    ,"CHIPA3_180322150048.df"
    ,"CHIPA4_180322150146.df"
    ,"CHIPA5_180322150238.df"
    ,"CHIPA6_180322150330.df"
    ,"CHIPA7_180322150423.df"
    ,"CHIPA8_180322150515.df"
    ,"CHIPA9_180322150605.df"
]

Fe_CHIPA1_file_name = [
    "Fe_CHIPA1_180327103104.df"
    ,"Fe_CHIPA1_180327103306.df"
    ,"Fe_CHIPA1_180327103508.df"
    ,"Fe_CHIPA1_180327103710.df"
    ,"Fe_CHIPA1_180327103912.df"
    ,"Fe_CHIPA1_180327104114.df"
    ,"Fe_CHIPA1_180327104316.df"
    ,"Fe_CHIPA1_180327104518.df"
    ,"Fe_CHIPA1_180327104720.df"
    ,"Fe_CHIPA1_180327104922.df"
    ,"Fe_CHIPA1_180327105124.df"
    ,"Fe_CHIPA1_180327105326.df"
    ,"Fe_CHIPA1_180327105528.df"
    ,"Fe_CHIPA1_180327105730.df"
    ,"Fe_CHIPA1_180327105932.df"
]

Fe_CHIPA2_file_name = [
    "Fe_CHIPA2_180327110357.df"
    ,"Fe_CHIPA2_180327110600.df"
    ,"Fe_CHIPA2_180327110802.df"
    ,"Fe_CHIPA2_180327111004.df"
    ,"Fe_CHIPA2_180327111206.df"
    ,"Fe_CHIPA2_180327111408.df"
    ,"Fe_CHIPA2_180327111610.df"
    ,"Fe_CHIPA2_180327111812.df"
    ,"Fe_CHIPA2_180327112014.df"
    ,"Fe_CHIPA2_180327112216.df"
    ,"Fe_CHIPA2_180327112418.df"
    ,"Fe_CHIPA2_180327112620.df"
    ,"Fe_CHIPA2_180327112822.df"
    ,"Fe_CHIPA2_180327113024.df"
    ,"Fe_CHIPA2_180327113227.df"
]

Fe_CHIPA3_file_name = [
    "Fe_CHIPA3_180327113643.df"
    ,"Fe_CHIPA3_180327113845.df"
    ,"Fe_CHIPA3_180327114047.df"
    ,"Fe_CHIPA3_180327114249.df"
    ,"Fe_CHIPA3_180327114451.df"
    ,"Fe_CHIPA3_180327114653.df"
    ,"Fe_CHIPA3_180327114855.df"
    ,"Fe_CHIPA3_180327115057.df"
    ,"Fe_CHIPA3_180327115300.df"
    ,"Fe_CHIPA3_180327115502.df"
    ,"Fe_CHIPA3_180327115704.df"
    ,"Fe_CHIPA3_180327115906.df"
    ,"Fe_CHIPA3_180327120108.df"
    ,"Fe_CHIPA3_180327120310.df"
    ,"Fe_CHIPA3_180327120512.df"
]

WeakFe_CHIPA1_file_name = [
    "WeakFe_CHIPA1_180329094037.df"
    ,"WeakFe_CHIPA1_180329094339.df"
    ,"WeakFe_CHIPA1_180329094641.df"
    ,"WeakFe_CHIPA1_180329094944.df"
    ,"WeakFe_CHIPA1_180329095246.df"
    ,"WeakFe_CHIPA1_180329095548.df"
    ,"WeakFe_CHIPA1_180329095850.df"
    ,"WeakFe_CHIPA1_180329100152.df"
    ,"WeakFe_CHIPA1_180329100454.df"
    ,"WeakFe_CHIPA1_180329100756.df"
    ,"WeakFe_CHIPA1_180329101058.df"
    ,"WeakFe_CHIPA1_180329101400.df"
    ,"WeakFe_CHIPA1_180329101702.df"
    ,"WeakFe_CHIPA1_180329102004.df"
    ,"WeakFe_CHIPA1_180329102306.df"
    ,"WeakFe_CHIPA1_180329102608.df"
    ,"WeakFe_CHIPA1_180329102910.df"
    ,"WeakFe_CHIPA1_180329103212.df"
    ,"WeakFe_CHIPA1_180329103514.df"
    ,"WeakFe_CHIPA1_180329103816.df"
    ,"WeakFe_CHIPA1_180329104118.df"
    ,"WeakFe_CHIPA1_180329104420.df"
    ,"WeakFe_CHIPA1_180329104722.df"
    ,"WeakFe_CHIPA1_180329105024.df"
    ,"WeakFe_CHIPA1_180329105326.df"
    ,"WeakFe_CHIPA1_180329105628.df"
    ,"WeakFe_CHIPA1_180329105930.df"
    ,"WeakFe_CHIPA1_180329110232.df"
    ,"WeakFe_CHIPA1_180329110534.df"
    ,"WeakFe_CHIPA1_180329110836.df"
    ,"WeakFe_CHIPA1_180329111139.df"
    ,"WeakFe_CHIPA1_180329111441.df"
    ,"WeakFe_CHIPA1_180329111743.df"
    ,"WeakFe_CHIPA1_180329112045.df"
    ,"WeakFe_CHIPA1_180329112347.df"
    ,"WeakFe_CHIPA1_180329112649.df"
    ,"WeakFe_CHIPA1_180329112951.df"
    ,"WeakFe_CHIPA1_180329113253.df"
    ,"WeakFe_CHIPA1_180329113555.df"
    ,"WeakFe_CHIPA1_180329113857.df"
]

WeakFe_CHIPA2_file_name = [
    "WeakFe_CHIPA2_180331104255.df"
    ,"WeakFe_CHIPA2_180331104557.df"
    ,"WeakFe_CHIPA2_180331104859.df"
    ,"WeakFe_CHIPA2_180331105201.df"
    ,"WeakFe_CHIPA2_180331105503.df"
    ,"WeakFe_CHIPA2_180331105805.df"
    ,"WeakFe_CHIPA2_180331110107.df"
    ,"WeakFe_CHIPA2_180331110409.df"
    ,"WeakFe_CHIPA2_180331110711.df"
    ,"WeakFe_CHIPA2_180331111013.df"
    ,"WeakFe_CHIPA2_180331111315.df"
    ,"WeakFe_CHIPA2_180331111617.df"
    ,"WeakFe_CHIPA2_180331111920.df"
    ,"WeakFe_CHIPA2_180331112222.df"
    ,"WeakFe_CHIPA2_180331112524.df"
    ,"WeakFe_CHIPA2_180331112826.df"
    ,"WeakFe_CHIPA2_180331113128.df"
    ,"WeakFe_CHIPA2_180331113430.df"
    ,"WeakFe_CHIPA2_180331113732.df"
    ,"WeakFe_CHIPA2_180331114034.df"
    ,"WeakFe_CHIPA2_180331114336.df"
    ,"WeakFe_CHIPA2_180331114638.df"
    ,"WeakFe_CHIPA2_180331114940.df"
    ,"WeakFe_CHIPA2_180331115242.df"
    ,"WeakFe_CHIPA2_180331115544.df"
    ,"WeakFe_CHIPA2_180331115846.df"
    ,"WeakFe_CHIPA2_180331120148.df"
    ,"WeakFe_CHIPA2_180331120450.df"
    ,"WeakFe_CHIPA2_180331120752.df"
    ,"WeakFe_CHIPA2_180331121054.df"
]

WeakFe_CHIPA3_file_name = [
    "WeakFe_CHIPA3_180331122029.df"
    ,"WeakFe_CHIPA3_180331122331.df"
    ,"WeakFe_CHIPA3_180331122633.df"
    ,"WeakFe_CHIPA3_180331122935.df"
    ,"WeakFe_CHIPA3_180331123237.df"
    ,"WeakFe_CHIPA3_180331123539.df"
    ,"WeakFe_CHIPA3_180331123841.df"
    ,"WeakFe_CHIPA3_180331124143.df"
    ,"WeakFe_CHIPA3_180331124446.df"
    ,"WeakFe_CHIPA3_180331124748.df"
    ,"WeakFe_CHIPA3_180331125050.df"
    ,"WeakFe_CHIPA3_180331125352.df"
    ,"WeakFe_CHIPA3_180331125654.df"
    ,"WeakFe_CHIPA3_180331125956.df"
    ,"WeakFe_CHIPA3_180331130258.df"
    ,"WeakFe_CHIPA3_180331130600.df"
    ,"WeakFe_CHIPA3_180331130902.df"
    ,"WeakFe_CHIPA3_180331131204.df"
    ,"WeakFe_CHIPA3_180331131506.df"
    ,"WeakFe_CHIPA3_180331131808.df"
    ,"WeakFe_CHIPA3_180331132110.df"
    ,"WeakFe_CHIPA3_180331132412.df"
    ,"WeakFe_CHIPA3_180331132714.df"
    ,"WeakFe_CHIPA3_180331133016.df"
    ,"WeakFe_CHIPA3_180331133318.df"
    ,"WeakFe_CHIPA3_180331133620.df"
    ,"WeakFe_CHIPA3_180331133922.df"
    ,"WeakFe_CHIPA3_180331134224.df"
    ,"WeakFe_CHIPA3_180331134526.df"
    ,"WeakFe_CHIPA3_180331134829.df"
]

WeakFe_CHIPA4_file_name = [
    "WeakFe_CHIPA4_180329115432.df"
    ,"WeakFe_CHIPA4_180329115734.df"
    ,"WeakFe_CHIPA4_180329120036.df"
    ,"WeakFe_CHIPA4_180329120338.df"
    ,"WeakFe_CHIPA4_180329120640.df"
    ,"WeakFe_CHIPA4_180329120942.df"
    ,"WeakFe_CHIPA4_180329121244.df"
    ,"WeakFe_CHIPA4_180329121546.df"
    ,"WeakFe_CHIPA4_180329121848.df"
    ,"WeakFe_CHIPA4_180329122150.df"
    ,"WeakFe_CHIPA4_180329122452.df"
    ,"WeakFe_CHIPA4_180329122754.df"
    ,"WeakFe_CHIPA4_180329123056.df"
    ,"WeakFe_CHIPA4_180329123358.df"
    ,"WeakFe_CHIPA4_180329123700.df"
    ,"WeakFe_CHIPA4_180329124002.df"
    ,"WeakFe_CHIPA4_180329124304.df"
    ,"WeakFe_CHIPA4_180329124606.df"
    ,"WeakFe_CHIPA4_180329124908.df"
    ,"WeakFe_CHIPA4_180329125210.df"
    ,"WeakFe_CHIPA4_180329125512.df"
    ,"WeakFe_CHIPA4_180329125815.df"
    ,"WeakFe_CHIPA4_180329130117.df"
    ,"WeakFe_CHIPA4_180329130419.df"
    ,"WeakFe_CHIPA4_180329130721.df"
    ,"WeakFe_CHIPA4_180329131023.df"
    ,"WeakFe_CHIPA4_180329131325.df"
    ,"WeakFe_CHIPA4_180329131627.df"
    ,"WeakFe_CHIPA4_180329131929.df"
    ,"WeakFe_CHIPA4_180329132231.df"
    ,"WeakFe_CHIPA4_180329132533.df"
    ,"WeakFe_CHIPA4_180329132835.df"
    ,"WeakFe_CHIPA4_180329133137.df"
    ,"WeakFe_CHIPA4_180329133439.df"
    ,"WeakFe_CHIPA4_180329133741.df"
    ,"WeakFe_CHIPA4_180329152839.df"
    ,"WeakFe_CHIPA4_180329153141.df"
    ,"WeakFe_CHIPA4_180329153443.df"
    ,"WeakFe_CHIPA4_180329153745.df"
    ,"WeakFe_CHIPA4_180329154047.df"
]

WeakFe_CHIPA5_file_name = [
    "WeakFe_CHIPA5_180331145314.df"
    ,"WeakFe_CHIPA5_180331145616.df"
    ,"WeakFe_CHIPA5_180331145918.df"
    ,"WeakFe_CHIPA5_180331150220.df"
    ,"WeakFe_CHIPA5_180331150522.df"
    ,"WeakFe_CHIPA5_180331150824.df"
    ,"WeakFe_CHIPA5_180331151126.df"
    ,"WeakFe_CHIPA5_180331151428.df"
    ,"WeakFe_CHIPA5_180331151730.df"
    ,"WeakFe_CHIPA5_180331152032.df"
    ,"WeakFe_CHIPA5_180331154303.df"
    ,"WeakFe_CHIPA5_180331154605.df"
    ,"WeakFe_CHIPA5_180331154907.df"
    ,"WeakFe_CHIPA5_180331155209.df"
    ,"WeakFe_CHIPA5_180331155511.df"
    ,"WeakFe_CHIPA5_180403201936.df"
    ,"WeakFe_CHIPA5_180403202238.df"
    ,"WeakFe_CHIPA5_180403202540.df"
    ,"WeakFe_CHIPA5_180403202842.df"
    ,"WeakFe_CHIPA5_180403203144.df"
    ,"WeakFe_CHIPA5_180403203446.df"
    ,"WeakFe_CHIPA5_180403203748.df"
    ,"WeakFe_CHIPA5_180403204050.df"
    ,"WeakFe_CHIPA5_180403204352.df"
    ,"WeakFe_CHIPA5_180403204654.df"
    ,"WeakFe_CHIPA5_180403204956.df"
    ,"WeakFe_CHIPA5_180403205258.df"
    ,"WeakFe_CHIPA5_180403205600.df"
    ,"WeakFe_CHIPA5_180403205902.df"
    ,"WeakFe_CHIPA5_180403210204.df"
]

WeakFe_CHIPA6_file_name = [
    "WeakFe_CHIPA6_180401131102.df"
    ,"WeakFe_CHIPA6_180401131404.df"
    ,"WeakFe_CHIPA6_180401131706.df"
    ,"WeakFe_CHIPA6_180401132008.df"
    ,"WeakFe_CHIPA6_180401132310.df"
    ,"WeakFe_CHIPA6_180401132612.df"
    ,"WeakFe_CHIPA6_180401132914.df"
    ,"WeakFe_CHIPA6_180401133216.df"
    ,"WeakFe_CHIPA6_180401133518.df"
    ,"WeakFe_CHIPA6_180401133820.df"
    ,"WeakFe_CHIPA6_180401134122.df"
    ,"WeakFe_CHIPA6_180401134424.df"
    ,"WeakFe_CHIPA6_180401134726.df"
    ,"WeakFe_CHIPA6_180401135028.df"
    ,"WeakFe_CHIPA6_180401135330.df"
    ,"WeakFe_CHIPA6_180401135632.df"
    ,"WeakFe_CHIPA6_180401135934.df"
    ,"WeakFe_CHIPA6_180401140236.df"
    ,"WeakFe_CHIPA6_180401140538.df"
    ,"WeakFe_CHIPA6_180401140840.df"
    ,"WeakFe_CHIPA6_180401141143.df"
    ,"WeakFe_CHIPA6_180401141445.df"
    ,"WeakFe_CHIPA6_180401141747.df"
    ,"WeakFe_CHIPA6_180401142049.df"
    ,"WeakFe_CHIPA6_180401142351.df"
    ,"WeakFe_CHIPA6_180401142653.df"
    ,"WeakFe_CHIPA6_180401142955.df"
    ,"WeakFe_CHIPA6_180401143257.df"
    ,"WeakFe_CHIPA6_180401143559.df"
    ,"WeakFe_CHIPA6_180401143901.df"
]

WeakFe_CHIPA7_file_name = [
    "WeakFe_CHIPA7_180410141222.df"
    ,"WeakFe_CHIPA7_180410141524.df"
    ,"WeakFe_CHIPA7_180410141826.df"
    ,"WeakFe_CHIPA7_180410142128.df"
    ,"WeakFe_CHIPA7_180410142431.df"
    ,"WeakFe_CHIPA7_180410142733.df"
    ,"WeakFe_CHIPA7_180410143035.df"
    ,"WeakFe_CHIPA7_180410143337.df"
    ,"WeakFe_CHIPA7_180410143639.df"
    ,"WeakFe_CHIPA7_180410143941.df"
    ,"WeakFe_CHIPA7_180410144243.df"
    ,"WeakFe_CHIPA7_180410144545.df"
    ,"WeakFe_CHIPA7_180410144847.df"
    ,"WeakFe_CHIPA7_180410145149.df"
    ,"WeakFe_CHIPA7_180410145451.df"
    ,"WeakFe_CHIPA7_180410145753.df"
    ,"WeakFe_CHIPA7_180410150055.df"
    ,"WeakFe_CHIPA7_180410150357.df"
    ,"WeakFe_CHIPA7_180410150659.df"
    ,"WeakFe_CHIPA7_180410151001.df"
    ,"WeakFe_CHIPA7_180410151303.df"
    ,"WeakFe_CHIPA7_180410151605.df"
    ,"WeakFe_CHIPA7_180410151907.df"
    ,"WeakFe_CHIPA7_180410152209.df"
    ,"WeakFe_CHIPA7_180410152512.df"
    ,"WeakFe_CHIPA7_180410152814.df"
    ,"WeakFe_CHIPA7_180410153116.df"
    ,"WeakFe_CHIPA7_180410153418.df"
    ,"WeakFe_CHIPA7_180410153720.df"
    ,"WeakFe_CHIPA7_180410154022.df"
    ,"WeakFe_CHIPA7_180410154324.df"
    ,"WeakFe_CHIPA7_180410154626.df"
    ,"WeakFe_CHIPA7_180410154928.df"
    ,"WeakFe_CHIPA7_180410155230.df"
    ,"WeakFe_CHIPA7_180410155532.df"
    ,"WeakFe_CHIPA7_180410155834.df"
    ,"WeakFe_CHIPA7_180410160136.df"
    ,"WeakFe_CHIPA7_180410160438.df"
    ,"WeakFe_CHIPA7_180410160740.df"
    ,"WeakFe_CHIPA7_180410161042.df"
]

WeakFe_CHIPA8_file_name = [
    "WeakFe_CHIPA8_180401144323.df"
    ,"WeakFe_CHIPA8_180401144625.df"
    ,"WeakFe_CHIPA8_180401144927.df"
    ,"WeakFe_CHIPA8_180401145229.df"
    ,"WeakFe_CHIPA8_180401145532.df"
    ,"WeakFe_CHIPA8_180401145834.df"
    ,"WeakFe_CHIPA8_180401150136.df"
    ,"WeakFe_CHIPA8_180401150438.df"
    ,"WeakFe_CHIPA8_180401150740.df"
    ,"WeakFe_CHIPA8_180401151042.df"
    ,"WeakFe_CHIPA8_180401151344.df"
    ,"WeakFe_CHIPA8_180401151646.df"
    ,"WeakFe_CHIPA8_180401151948.df"
    ,"WeakFe_CHIPA8_180401152250.df"
    ,"WeakFe_CHIPA8_180401152552.df"
    ,"WeakFe_CHIPA8_180401152854.df"
    ,"WeakFe_CHIPA8_180401153156.df"
    ,"WeakFe_CHIPA8_180401153458.df"
    ,"WeakFe_CHIPA8_180401153800.df"
    ,"WeakFe_CHIPA8_180401154102.df"
    ,"WeakFe_CHIPA8_180401154404.df"
    ,"WeakFe_CHIPA8_180401154706.df"
    ,"WeakFe_CHIPA8_180401155008.df"
    ,"WeakFe_CHIPA8_180401155310.df"
    ,"WeakFe_CHIPA8_180401155612.df"
    ,"WeakFe_CHIPA8_180401155914.df"
    ,"WeakFe_CHIPA8_180401160216.df"
    ,"WeakFe_CHIPA8_180401160518.df"
    ,"WeakFe_CHIPA8_180401160821.df"
    ,"WeakFe_CHIPA8_180401161123.df"
]

WeakFe_CHIPA9_file_name = [
    "WeakFe_CHIPA9_180403154139.df"
    ,"WeakFe_CHIPA9_180403154441.df"
    ,"WeakFe_CHIPA9_180403154743.df"
    ,"WeakFe_CHIPA9_180403155045.df"
    ,"WeakFe_CHIPA9_180403155347.df"
    ,"WeakFe_CHIPA9_180403155649.df"
    ,"WeakFe_CHIPA9_180403155951.df"
    ,"WeakFe_CHIPA9_180403160253.df"
    ,"WeakFe_CHIPA9_180403160555.df"
    ,"WeakFe_CHIPA9_180403160857.df"
    ,"WeakFe_CHIPA9_180403161159.df"
    ,"WeakFe_CHIPA9_180403161501.df"
    ,"WeakFe_CHIPA9_180403161803.df"
    ,"WeakFe_CHIPA9_180403162105.df"
    ,"WeakFe_CHIPA9_180403162407.df"
    ,"WeakFe_CHIPA9_180403162710.df"
    ,"WeakFe_CHIPA9_180403163012.df"
    ,"WeakFe_CHIPA9_180403163314.df"
    ,"WeakFe_CHIPA9_180403163616.df"
    ,"WeakFe_CHIPA9_180403163918.df"
    ,"WeakFe_CHIPA9_180403164220.df"
    ,"WeakFe_CHIPA9_180403164522.df"
    ,"WeakFe_CHIPA9_180403164824.df"
    ,"WeakFe_CHIPA9_180403165126.df"
    ,"WeakFe_CHIPA9_180403165428.df"
    ,"WeakFe_CHIPA9_180403165730.df"
    ,"WeakFe_CHIPA9_180403170032.df"
    ,"WeakFe_CHIPA9_180403170334.df"
    ,"WeakFe_CHIPA9_180403170636.df"
    ,"WeakFe_CHIPA9_180403170938.df"
]

Sr_CHIPA1_file_name = [
    "Sr_CHIPA1_180418224513.df"
    ,"Sr_CHIPA1_180418224815.df"
    ,"Sr_CHIPA1_180418225117.df"
    ,"Sr_CHIPA1_180418225419.df"
    ,"Sr_CHIPA1_180418225722.df"
    ,"Sr_CHIPA1_180418230024.df"
    ,"Sr_CHIPA1_180418230326.df"
    ,"Sr_CHIPA1_180418230628.df"
    ,"Sr_CHIPA1_180418230930.df"
    ,"Sr_CHIPA1_180418231232.df"
    ,"Sr_CHIPA1_180418231534.df"
    ,"Sr_CHIPA1_180418231836.df"
    ,"Sr_CHIPA1_180418232138.df"
    ,"Sr_CHIPA1_180418232441.df"
    ,"Sr_CHIPA1_180418232743.df"
    ,"Sr_CHIPA1_180418233045.df"
    ,"Sr_CHIPA1_180418233347.df"
    ,"Sr_CHIPA1_180418233649.df"
    ,"Sr_CHIPA1_180418233951.df"
    ,"Sr_CHIPA1_180418234253.df"
    ,"Sr_CHIPA1_180418234555.df"
    ,"Sr_CHIPA1_180418234857.df"
    ,"Sr_CHIPA1_180418235159.df"
    ,"Sr_CHIPA1_180418235501.df"
    ,"Sr_CHIPA1_180418235803.df"
    ,"Sr_CHIPA1_180419000105.df"
    ,"Sr_CHIPA1_180419000407.df"
    ,"Sr_CHIPA1_180419000709.df"
    ,"Sr_CHIPA1_180419001012.df"
    ,"Sr_CHIPA1_180419001314.df"
    ,"Sr_CHIPA1_180419001616.df"
    ,"Sr_CHIPA1_180419001918.df"
    ,"Sr_CHIPA1_180419002220.df"
    ,"Sr_CHIPA1_180419002522.df"
    ,"Sr_CHIPA1_180419002824.df"
    ,"Sr_CHIPA1_180419003126.df"
    ,"Sr_CHIPA1_180419003429.df"
    ,"Sr_CHIPA1_180419003731.df"
    ,"Sr_CHIPA1_180419004033.df"
    ,"Sr_CHIPA1_180419004335.df"
    ,"Sr_CHIPA1_180419004637.df"
    ,"Sr_CHIPA1_180419004939.df"
    ,"Sr_CHIPA1_180419005241.df"
    ,"Sr_CHIPA1_180419005543.df"
    ,"Sr_CHIPA1_180419005845.df"
    ,"Sr_CHIPA1_180419010147.df"
    ,"Sr_CHIPA1_180419010449.df"
    ,"Sr_CHIPA1_180419010751.df"
    ,"Sr_CHIPA1_180419011053.df"
    ,"Sr_CHIPA1_180419011355.df"
    ,"Sr_CHIPA1_180419011658.df"
    ,"Sr_CHIPA1_180419012000.df"
    ,"Sr_CHIPA1_180419012302.df"
    ,"Sr_CHIPA1_180419012604.df"
    ,"Sr_CHIPA1_180419012906.df"
    ,"Sr_CHIPA1_180419013208.df"
    ,"Sr_CHIPA1_180419013510.df"
    ,"Sr_CHIPA1_180419013812.df"
    ,"Sr_CHIPA1_180419014114.df"
    ,"Sr_CHIPA1_180419014417.df"
]

Sr_CHIPA2_file_name = [
    "Sr_CHIPA2_180418191810.df"
    ,"Sr_CHIPA2_180418192112.df"
    ,"Sr_CHIPA2_180418192414.df"
    ,"Sr_CHIPA2_180418192716.df"
    ,"Sr_CHIPA2_180418193018.df"
    ,"Sr_CHIPA2_180418193320.df"
    ,"Sr_CHIPA2_180418193623.df"
    ,"Sr_CHIPA2_180418193925.df"
    ,"Sr_CHIPA2_180418194227.df"
    ,"Sr_CHIPA2_180418194529.df"
    ,"Sr_CHIPA2_180418194831.df"
    ,"Sr_CHIPA2_180418195133.df"
    ,"Sr_CHIPA2_180418195435.df"
    ,"Sr_CHIPA2_180418195737.df"
    ,"Sr_CHIPA2_180418200039.df"
    ,"Sr_CHIPA2_180418200341.df"
    ,"Sr_CHIPA2_180418200643.df"
    ,"Sr_CHIPA2_180418200945.df"
    ,"Sr_CHIPA2_180418201247.df"
    ,"Sr_CHIPA2_180418201549.df"
    ,"Sr_CHIPA2_180418201852.df"
    ,"Sr_CHIPA2_180418202154.df"
    ,"Sr_CHIPA2_180418202456.df"
    ,"Sr_CHIPA2_180418202758.df"
    ,"Sr_CHIPA2_180418203100.df"
    ,"Sr_CHIPA2_180418203402.df"
    ,"Sr_CHIPA2_180418203704.df"
    ,"Sr_CHIPA2_180418204006.df"
    ,"Sr_CHIPA2_180418204309.df"
    ,"Sr_CHIPA2_180418204611.df"
    ,"Sr_CHIPA2_180418204913.df"
    ,"Sr_CHIPA2_180418205215.df"
    ,"Sr_CHIPA2_180418205517.df"
    ,"Sr_CHIPA2_180418205819.df"
    ,"Sr_CHIPA2_180418210121.df"
    ,"Sr_CHIPA2_180418210423.df"
    ,"Sr_CHIPA2_180418210725.df"
    ,"Sr_CHIPA2_180418211027.df"
    ,"Sr_CHIPA2_180418211329.df"
    ,"Sr_CHIPA2_180418211631.df"
    ,"Sr_CHIPA2_180418211933.df"
    ,"Sr_CHIPA2_180418212235.df"
    ,"Sr_CHIPA2_180418212538.df"
    ,"Sr_CHIPA2_180418212840.df"
    ,"Sr_CHIPA2_180418213142.df"
    ,"Sr_CHIPA2_180418213444.df"
    ,"Sr_CHIPA2_180418213746.df"
    ,"Sr_CHIPA2_180418214048.df"
    ,"Sr_CHIPA2_180418214350.df"
    ,"Sr_CHIPA2_180418214652.df"
    ,"Sr_CHIPA2_180418214954.df"
    ,"Sr_CHIPA2_180418215256.df"
    ,"Sr_CHIPA2_180418215559.df"
    ,"Sr_CHIPA2_180418215901.df"
    ,"Sr_CHIPA2_180418220203.df"
    ,"Sr_CHIPA2_180418220505.df"
    ,"Sr_CHIPA2_180418220807.df"
    ,"Sr_CHIPA2_180418221109.df"
    ,"Sr_CHIPA2_180418221411.df"
    ,"Sr_CHIPA2_180418221713.df"
]

Sr_CHIPA3_file_name = [
    "Sr_CHIPA3_180418161027.df"
    ,"Sr_CHIPA3_180418161329.df"
    ,"Sr_CHIPA3_180418161631.df"
    ,"Sr_CHIPA3_180418161933.df"
    ,"Sr_CHIPA3_180418162235.df"
    ,"Sr_CHIPA3_180418162537.df"
    ,"Sr_CHIPA3_180418162839.df"
    ,"Sr_CHIPA3_180418163141.df"
    ,"Sr_CHIPA3_180418163443.df"
    ,"Sr_CHIPA3_180418163745.df"
    ,"Sr_CHIPA3_180418164047.df"
    ,"Sr_CHIPA3_180418164349.df"
    ,"Sr_CHIPA3_180418164651.df"
    ,"Sr_CHIPA3_180418164953.df"
    ,"Sr_CHIPA3_180418165256.df"
    ,"Sr_CHIPA3_180418165558.df"
    ,"Sr_CHIPA3_180418165900.df"
    ,"Sr_CHIPA3_180418170202.df"
    ,"Sr_CHIPA3_180418170504.df"
    ,"Sr_CHIPA3_180418170806.df"
    ,"Sr_CHIPA3_180418171108.df"
    ,"Sr_CHIPA3_180418171410.df"
    ,"Sr_CHIPA3_180418171712.df"
    ,"Sr_CHIPA3_180418172014.df"
    ,"Sr_CHIPA3_180418172316.df"
    ,"Sr_CHIPA3_180418172618.df"
    ,"Sr_CHIPA3_180418172921.df"
    ,"Sr_CHIPA3_180418173223.df"
    ,"Sr_CHIPA3_180418173525.df"
    ,"Sr_CHIPA3_180418173827.df"
    ,"Sr_CHIPA3_180418174129.df"
    ,"Sr_CHIPA3_180418174431.df"
    ,"Sr_CHIPA3_180418174733.df"
    ,"Sr_CHIPA3_180418175035.df"
    ,"Sr_CHIPA3_180418175337.df"
    ,"Sr_CHIPA3_180418175639.df"
    ,"Sr_CHIPA3_180418175941.df"
    ,"Sr_CHIPA3_180418180243.df"
    ,"Sr_CHIPA3_180418180546.df"
    ,"Sr_CHIPA3_180418180848.df"
    ,"Sr_CHIPA3_180418181150.df"
    ,"Sr_CHIPA3_180418181452.df"
    ,"Sr_CHIPA3_180418181754.df"
    ,"Sr_CHIPA3_180418182056.df"
    ,"Sr_CHIPA3_180418182358.df"
    ,"Sr_CHIPA3_180418182700.df"
    ,"Sr_CHIPA3_180418183003.df"
    ,"Sr_CHIPA3_180418183305.df"
    ,"Sr_CHIPA3_180418183607.df"
    ,"Sr_CHIPA3_180418183909.df"
    ,"Sr_CHIPA3_180418184211.df"
    ,"Sr_CHIPA3_180418184513.df"
    ,"Sr_CHIPA3_180418184815.df"
    ,"Sr_CHIPA3_180418185117.df"
    ,"Sr_CHIPA3_180418185419.df"
    ,"Sr_CHIPA3_180418185721.df"
    ,"Sr_CHIPA3_180418190023.df"
    ,"Sr_CHIPA3_180418190325.df"
    ,"Sr_CHIPA3_180418190627.df"
    ,"Sr_CHIPA3_180418190929.df"
]

May_Sr_CHIPA1_file_name = [
    "Sr_CHIPA1_180429123559.df"
    ,"Sr_CHIPA1_180429124601.df"
    ,"Sr_CHIPA1_180429125603.df"
    ,"Sr_CHIPA1_180429130605.df"
    ,"Sr_CHIPA1_180429131607.df"
    ,"Sr_CHIPA1_180429132609.df"
    ,"Sr_CHIPA1_180429133611.df"
    ,"Sr_CHIPA1_180429134613.df"
    ,"Sr_CHIPA1_180429135615.df"
    ,"Sr_CHIPA1_180429140617.df"
    ,"Sr_CHIPA1_180429141619.df"
    ,"Sr_CHIPA1_180429142621.df"
    ,"Sr_CHIPA1_180429143623.df"
    ,"Sr_CHIPA1_180429144625.df"
    ,"Sr_CHIPA1_180429145627.df"
    ,"Sr_CHIPA1_180429150629.df"
    ,"Sr_CHIPA1_180429151631.df"
    ,"Sr_CHIPA1_180429152633.df"
    ,"Sr_CHIPA1_180429153635.df"
    ,"Sr_CHIPA1_180429154637.df"
    ,"Sr_CHIPA1_180429155639.df"
    ,"Sr_CHIPA1_180429160641.df"
    ,"Sr_CHIPA1_180429161643.df"
    ,"Sr_CHIPA1_180429162645.df"
    ,"Sr_CHIPA1_180429163647.df"
    ,"Sr_CHIPA1_180429164649.df"
    ,"Sr_CHIPA1_180429165651.df"
    ,"Sr_CHIPA1_180429170653.df"
    ,"Sr_CHIPA1_180429171655.df"
    ,"Sr_CHIPA1_180429172657.df"
    ,"Sr_CHIPA1_180429173659.df"
    ,"Sr_CHIPA1_180429174701.df"
    ,"Sr_CHIPA1_180429175703.df"
    ,"Sr_CHIPA1_180429180705.df"
    ,"Sr_CHIPA1_180429181707.df"
    ,"Sr_CHIPA1_180429182709.df"
    ,"Sr_CHIPA1_180429183711.df"
    ,"Sr_CHIPA1_180429184713.df"
    ,"Sr_CHIPA1_180429185715.df"
    ,"Sr_CHIPA1_180429190717.df"
]

May_Sr_CHIPA2_file_name = [
  "Sr_CHIPA2_180429201131.df"
  ,"Sr_CHIPA2_180429202133.df"
  ,"Sr_CHIPA2_180429203135.df"
  ,"Sr_CHIPA2_180429204137.df"
  ,"Sr_CHIPA2_180429205139.df"
  ,"Sr_CHIPA2_180429210141.df"
  ,"Sr_CHIPA2_180429211143.df"
  ,"Sr_CHIPA2_180429212145.df"
  ,"Sr_CHIPA2_180429213147.df"
  ,"Sr_CHIPA2_180429214149.df"
  ,"Sr_CHIPA2_180429215151.df"
  ,"Sr_CHIPA2_180429220153.df"
  ,"Sr_CHIPA2_180429221155.df"
  ,"Sr_CHIPA2_180429222157.df"
  ,"Sr_CHIPA2_180429223159.df"
  ,"Sr_CHIPA2_180429224201.df"
  ,"Sr_CHIPA2_180429225203.df"
  ,"Sr_CHIPA2_180429230205.df"
  ,"Sr_CHIPA2_180429231207.df"
  ,"Sr_CHIPA2_180429232209.df"
  ,"Sr_CHIPA2_180429233211.df"
  ,"Sr_CHIPA2_180429234213.df"
  ,"Sr_CHIPA2_180429235215.df"
  ,"Sr_CHIPA2_180430000217.df"
  ,"Sr_CHIPA2_180430001219.df"
  ,"Sr_CHIPA2_180430002221.df"
  ,"Sr_CHIPA2_180430003223.df"
  ,"Sr_CHIPA2_180430004225.df"
  ,"Sr_CHIPA2_180430005227.df"
  ,"Sr_CHIPA2_180430010229.df"
  ,"Sr_CHIPA2_180430011231.df"
  ,"Sr_CHIPA2_180430012233.df"
  ,"Sr_CHIPA2_180430013235.df"
  ,"Sr_CHIPA2_180430014237.df"
  ,"Sr_CHIPA2_180430015239.df"
  ,"Sr_CHIPA2_180430020241.df"
  ,"Sr_CHIPA2_180430021243.df"
  ,"Sr_CHIPA2_180430022245.df"
  ,"Sr_CHIPA2_180430023247.df"
  ,"Sr_CHIPA2_180430024249.df"
]

May_Sr_CHIPA3_file_name=[
  "Sr_CHIPA3_180430030943.df"
  ,"Sr_CHIPA3_180430031945.df"
  ,"Sr_CHIPA3_180430032947.df"
  ,"Sr_CHIPA3_180430033949.df"
  ,"Sr_CHIPA3_180430034951.df"
  ,"Sr_CHIPA3_180430035953.df"
  ,"Sr_CHIPA3_180430040955.df"
  ,"Sr_CHIPA3_180430041957.df"
  ,"Sr_CHIPA3_180430042959.df"
  ,"Sr_CHIPA3_180430044001.df"
  ,"Sr_CHIPA3_180430045003.df"
  ,"Sr_CHIPA3_180430050005.df"
  ,"Sr_CHIPA3_180430051007.df"
  ,"Sr_CHIPA3_180430052009.df"
  ,"Sr_CHIPA3_180430053011.df"
  ,"Sr_CHIPA3_180430054013.df"
  ,"Sr_CHIPA3_180430055015.df"
  ,"Sr_CHIPA3_180430060017.df"
  ,"Sr_CHIPA3_180430061019.df"
  ,"Sr_CHIPA3_180430062021.df"
  ,"Sr_CHIPA3_180430063023.df"
  ,"Sr_CHIPA3_180430064025.df"
  ,"Sr_CHIPA3_180430065027.df"
  ,"Sr_CHIPA3_180430070029.df"
  ,"Sr_CHIPA3_180430071031.df"
  ,"Sr_CHIPA3_180430072033.df"
  ,"Sr_CHIPA3_180430073035.df"
  ,"Sr_CHIPA3_180430074037.df"
  ,"Sr_CHIPA3_180430075039.df"
  ,"Sr_CHIPA3_180430080041.df"
  ,"Sr_CHIPA3_180430081043.df"
  ,"Sr_CHIPA3_180430082045.df"
  ,"Sr_CHIPA3_180430083047.df"
  ,"Sr_CHIPA3_180430084049.df"
  ,"Sr_CHIPA3_180430085051.df"
  ,"Sr_CHIPA3_180430090054.df"
  ,"Sr_CHIPA3_180430091056.df"
  ,"Sr_CHIPA3_180430092058.df"
  ,"Sr_CHIPA3_180430093100.df"
  ,"Sr_CHIPA3_180430094102.df"
]

May_Sr_CHIPA4_file_name=[
  "Sr_CHIPA4_180430105324.df"
  ,"Sr_CHIPA4_180430110326.df"
  ,"Sr_CHIPA4_180430111328.df"
  ,"Sr_CHIPA4_180430112330.df"
  ,"Sr_CHIPA4_180430113332.df"
  ,"Sr_CHIPA4_180430114334.df"
  ,"Sr_CHIPA4_180430115336.df"
  ,"Sr_CHIPA4_180430120339.df"
  ,"Sr_CHIPA4_180430121341.df"
  ,"Sr_CHIPA4_180430122343.df"
  ,"Sr_CHIPA4_180430123345.df"
  ,"Sr_CHIPA4_180430124347.df"
  ,"Sr_CHIPA4_180430125349.df"
  ,"Sr_CHIPA4_180430130351.df"
  ,"Sr_CHIPA4_180430131353.df"
  ,"Sr_CHIPA4_180430132355.df"
  ,"Sr_CHIPA4_180430133357.df"
  ,"Sr_CHIPA4_180430134400.df"
  ,"Sr_CHIPA4_180430135402.df"
  ,"Sr_CHIPA4_180430140404.df"
  ,"Sr_CHIPA4_180430141406.df"
  ,"Sr_CHIPA4_180430142408.df"
  ,"Sr_CHIPA4_180430143410.df"
  ,"Sr_CHIPA4_180430144412.df"
  ,"Sr_CHIPA4_180430145414.df"
  ,"Sr_CHIPA4_180430150416.df"
  ,"Sr_CHIPA4_180430151418.df"
  ,"Sr_CHIPA4_180430152420.df"
  ,"Sr_CHIPA4_180430153422.df"
  ,"Sr_CHIPA4_180430154424.df"
  ,"Sr_CHIPA4_180430155426.df"
  ,"Sr_CHIPA4_180430160428.df"
  ,"Sr_CHIPA4_180430161430.df"
  ,"Sr_CHIPA4_180430162432.df"
  ,"Sr_CHIPA4_180430163434.df"
  ,"Sr_CHIPA4_180430164436.df"
  ,"Sr_CHIPA4_180430165438.df"
  ,"Sr_CHIPA4_180430170440.df"
  ,"Sr_CHIPA4_180430171443.df"
  ,"Sr_CHIPA4_180430172445.df"
]

May_Sr_CHIPA7_file_name = [
  "Sr_CHIPA7_180430175502.df"
  ,"Sr_CHIPA7_180430180504.df"
  ,"Sr_CHIPA7_180430181506.df"
  ,"Sr_CHIPA7_180430182508.df"
  ,"Sr_CHIPA7_180430183510.df"
  ,"Sr_CHIPA7_180430184512.df"
  ,"Sr_CHIPA7_180430185514.df"
  ,"Sr_CHIPA7_180430190516.df"
  ,"Sr_CHIPA7_180430191518.df"
  ,"Sr_CHIPA7_180430192520.df"
  ,"Sr_CHIPA7_180430193522.df"
  ,"Sr_CHIPA7_180430194524.df"
  ,"Sr_CHIPA7_180430195526.df"
  ,"Sr_CHIPA7_180430200528.df"
  ,"Sr_CHIPA7_180430201530.df"
  ,"Sr_CHIPA7_180430202532.df"
  ,"Sr_CHIPA7_180430203534.df"
  ,"Sr_CHIPA7_180430204536.df"
  ,"Sr_CHIPA7_180430205538.df"
  ,"Sr_CHIPA7_180430210540.df"
  ,"Sr_CHIPA7_180430211542.df"
  ,"Sr_CHIPA7_180430212544.df"
  ,"Sr_CHIPA7_180430213546.df"
  ,"Sr_CHIPA7_180430214548.df"
  ,"Sr_CHIPA7_180430215550.df"
  ,"Sr_CHIPA7_180430220552.df"
  ,"Sr_CHIPA7_180430221554.df"
  ,"Sr_CHIPA7_180430222556.df"
  ,"Sr_CHIPA7_180430223558.df"
  ,"Sr_CHIPA7_180430224600.df"
  ,"Sr_CHIPA7_180430225602.df"
  ,"Sr_CHIPA7_180430230604.df"
  ,"Sr_CHIPA7_180430231606.df"
  ,"Sr_CHIPA7_180430232608.df"
  ,"Sr_CHIPA7_180430233610.df"
  ,"Sr_CHIPA7_180430234612.df"
  ,"Sr_CHIPA7_180430235614.df"
  ,"Sr_CHIPA7_180501000616.df"
  ,"Sr_CHIPA7_180501001618.df"
  ,"Sr_CHIPA7_180501002620.df"
]

parser = argparse.ArgumentParser(description='JadePix Analysis Config')
parser.add_argument('-s',
                    action='store',
                    dest='start',
                    default=1,
                    type=int,
                    help='start analysis file')

parser.add_argument('-e',
                    action='store',
                    dest='end',
                    default=2,
                    type=int,
                    help='end analysis file')

parser.add_argument('-c',
                    action='store',
                    dest='chip_number',
                    default=1,
                    type=int,
                    help='chip number')

parser.add_argument('-n',
                    action='store',
                    dest='source_name',
                    default="WeakFe",
                    type=str,
                    help='source_name')

parser.add_argument('-t',
                    action='store',
                    dest='template_json',
                    default="WeakFe",
                    type=str,
                    help='template_json')

ARGS = parser.parse_args()

def get_file_name(source_name,chip_number):
    if(source_name=="Noise"):
        infile_name = source_name+"_file_name"
        outfile_name = source_name+"_CHIPA" + str(chip_number)
    else:
        infile_name = source_name+"_CHIPA"+ str(chip_number) +"_file_name"
        outfile_name = source_name+"_CHIPA" + str(chip_number)

    return [infile_name, outfile_name]

def gen_noise_config():

    for i in range(ARGS.start,ARGS.end):

      print("================== start >>>>>>>>>>\n")

      config_file = "config/"+"Noise_CHIPA"+ str(i) +"_run00001.json"

      copy_cmd = "cp "+ARGS.template_json+" "+ config_file

      subprocess.call(copy_cmd, shell=True)

      file_name = get_file_name(ARGS.source_name,i)
      in_file_name = globals()[file_name[0]]
      out_file_name = file_name[1]

      # infile
      in_cmd = "sed -n 15p " + config_file

      in_str_cmd = str(subprocess.check_output(in_cmd, shell=True),'utf-8')

      in_file = in_str_cmd.split("/")[-1][:-2]

      in_rep_cmd = "sed -i 15s/" + in_file + "/" + in_file_name[i-1] + "/g " + config_file

      subprocess.call(in_rep_cmd, shell=True)


      # outfile
      out_cmd = "sed -n 21p " + config_file

      out_str_cmd = str(subprocess.check_output(out_cmd, shell=True),'utf-8')

      out_file = out_str_cmd.split("/")[-1][:-3]

      out_rep_cmd = "sed -i 21s/" + out_file + "/" + out_file_name + "_1"+ "/g " + config_file

      subprocess.call(out_rep_cmd, shell=True)


      print(str(subprocess.check_output(in_cmd, shell=True),'utf-8'))

      print(str(subprocess.check_output(out_cmd, shell=True),'utf-8'))

      time.sleep(0.1)

      print("\n<<<<<<<<<<<<<<<<<< end ==============\n\n")


def gen_config():

    for i in range(ARGS.start,ARGS.end):

      print("================== start >>>>>>>>>>\n")

      config_file = "config/"+ARGS.source_name+"_CHIPA" + str(ARGS.chip_number) + "_run" + str(i).zfill(5) + ".json"

      copy_cmd = "cp "+ARGS.template_json+" "+ config_file

      subprocess.call(copy_cmd, shell=True)

      file_name = get_file_name(ARGS.source_name,ARGS.chip_number)
      in_file_name = globals()[file_name[0]]
      out_file_name = file_name[1]

      # infile
      in_cmd = "sed -n 15p " + config_file

      in_str_cmd = str(subprocess.check_output(in_cmd, shell=True),'utf-8')

      in_file = in_str_cmd.split("/")[-1][:-2]

      in_rep_cmd = "sed -i 15s/" + in_file + "/" + in_file_name[i-1] + "/g " + config_file

      subprocess.call(in_rep_cmd, shell=True)


      # outfile
      out_cmd = "sed -n 21p " + config_file

      out_str_cmd = str(subprocess.check_output(out_cmd, shell=True),'utf-8')

      out_file = out_str_cmd.split("/")[-1][:-3]

      out_rep_cmd = "sed -i 21s/" + out_file + "/" + out_file_name + "_" + str(i) + "/g " + config_file

      subprocess.call(out_rep_cmd, shell=True)


      print(str(subprocess.check_output(in_cmd, shell=True),'utf-8'))

      print(str(subprocess.check_output(out_cmd, shell=True),'utf-8'))

      time.sleep(0.1)

      print("\n<<<<<<<<<<<<<<<<<< end ==============\n\n")

def main():
    if(ARGS.source_name == "Noise"):
        gen_noise_config()
    else:
        gen_config()

if __name__ == "__main__":
    main()
