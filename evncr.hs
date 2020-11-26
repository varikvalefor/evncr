-- TODO: IMPLEMENT SLEEPING.

import System.Process;
import System.Environment;
import Text.Printf;

thingToInt :: Char -> [Int];
thingToInt theShift = [(prefixOne theShift), (prefixTwo theShift), (meatAndPotato theShift)];

prefixOne :: Char -> Int;
prefixOne theShift
             | (shifter < 58) && (shifter >= 48) = 129
             | otherwise = 128
             where shifter = (fromEnum theShift)

prefixTwo :: Char -> Int;
prefixTwo theShift
             | shifter < 48 = 0
             | shifter < 58 = 1
             | shifter < 65 = 0
             | shifter < 91 = 3
             | shifter < 97 = 0
             | shifter < 123 = 4
             where shifter = (fromEnum theShift)

meatAndPotato :: Char -> Int;
meatAndPotato theShift
                 | (shifter > 96) && (shifter < 123) = (shifter - 32)
                 | shifter `elem` [62,93,125] = (shifter - 2)
                 | shifter == 41 = 40
                 | otherwise = shifter
                 where shifter = (fromEnum theShift)

toFileName :: Int -> [Char];
toFileName theShift = ("/usr/local/share/evncr/" ++ (show theShift) ++ ".wav");

outputSound :: [Int] -> [IO String];
outputSound intRep = map (playFile) (map toFileName intRep);

playFile :: [Char] -> IO String;
playFile filename = readProcess "mplayer " [filename] "";

main = do
  theInput <- getLine;
  print (map (thingToInt) theInput);
  let fuck = map (outputSound) (map (thingToInt) theInput);
  printf "";
