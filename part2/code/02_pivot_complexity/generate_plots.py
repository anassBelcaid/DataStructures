"""
Python Scritp to generate the plot for the complexity analysis for a two sum
problem

Author: A.Belcaid
date : 2021-04-10
"""

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import argparse



#default parser
parser = argparse.ArgumentParser()
parser.add_argument("-l","--log",type=bool,help="Produce the logarithmic plot",default=False)
#parse arguments
args = parser.parse_args()
plt.xkcd(scale=1, length=100, randomness=2)
plt.style.use("bmh")


if __name__ == "__main__":

   
    #loading the data
    data = np.loadtxt("./results.csv", skiprows=1)

    #plotting the simple data
    if args.log:
        data = np.log(data)


    print(data)


    plt.plot(data[:,0], data[:,1], label="brute")
    plt.plot(data[:,0], data[:,2], label="setSearch")

    if args.log:
        a_brute, _ = np.polyfit(data[:,0], data[:,1], 1)
        a_set, _ = np.polyfit(data[:,0], data[:,2], 1)
        plt.title("linear : {:.2f} set: {:.2f}".format(a_brute, a_set))
    plt.legend()
    name = "logarithmic.png" if args.log else "linear.png"
    plt.savefig(name)
    plt.show()













