#!/besfs/groups/higgs/users/chenlj/software/anaconda3/bin/python

import subprocess
import time
import argparse

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

ARGS = parser.parse_args()

def get_file_name(chip_number):
    infile_name = "WeakFe_CHIPA"+ str(chip_number) +"_file_name"
    outfile_name = "WeakFe_CHIPA" + str(chip_number)
    return [infile_name, outfile_name]

def gen_config():

    for i in range(ARGS.start,ARGS.end):

      print("================== start >>>>>>>>>>\n")

      config_file = "config/CHIPA" + str(ARGS.chip_number) + "_run" + str(i).zfill(5) + ".json"

      copy_cmd = "cp config/CHIPA" + str(ARGS.chip_number) + "_run00001.json " + config_file

      subprocess.call(copy_cmd, shell=True)

      file_name = get_file_name(ARGS.chip_number)
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

      time.sleep(1)

      print("\n<<<<<<<<<<<<<<<<<< end ==============\n\n")

def main():
    gen_config()

if __name__ == "__main__":
    main()
