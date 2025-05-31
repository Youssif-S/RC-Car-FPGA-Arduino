LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY the_great_sensor_brain IS 
PORT (
	back_sens : IN STD_LOGIC;
	left_sens : IN STD_LOGIC;
	front_sens : IN STD_LOGIC;
	right_sens : IN STD_LOGIC;
	light_sens : IN STD_LOGIC;
	
	light_out : OUT STD_LOGIC;
	left_motor : OUT STD_LOGIC;
	right_motor : OUT STD_LOGIC);

END the_great_sensor_brain;


ARCHITECTURE structure OF the_great_sensor_brain IS
	signal sensors : STD_LOGIC_VECTOR (3 DOWNTO 0);
BEGIN
	
	sensors <= back_sens & left_sens & front_sens & right_sens;

	
	PROCESS (sensors, light_sens)
	BEGIN
	
	CASE light_sens IS
		WHEN '0' =>
			light_out <= '0';
		WHEN others =>
			light_out <= '1';
	END CASE;
	
	CASE sensors IS
		WHEN "0000" =>
			left_motor <= '0';
			right_motor <= '0';
		WHEN "1000" =>
			left_motor <= '1';
			right_motor <='1';
		WHEN "0100" =>
			left_motor <= '0';
			right_motor <= '1';
		WHEN "0001"=>
			left_motor <= '1';
			right_motor <= '0';
		WHEN others =>
			left_motor <= '0';
			right_motor <= '0';
	END CASE;

	 
	 END PROCESS;
END structure;