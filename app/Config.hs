module Config where

-- | delay_intraChar denotes the delay between readings of
-- intra-character phrases, e.g., "ARABIC" and "MAJUSCULE".
-- Times are given in microseconds.
delay_intraChar :: Int;
delay_intraChar = 125 * 10^3;

-- | delay_intraChar denotes the delay between readings of
-- characters, e.g., "LATIN MAJUSCULE ALFA" and "LATIN MAJUSCULE
-- WHISKEY".
-- Times are given in microseconds.
delay_interChar :: Int;
delay_interChar = 250 * 10^3;

-- | soundDir is the directory which contains the voice samples of
-- EVANNOUNCER.
soundDir :: FilePath;
soundDir = "/usr/local/share/evncr/";
