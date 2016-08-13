#ifndef ROM_H_
# define ROM_H_

# define MIN_ROM_SIZE	0x8000

typedef struct s_gameboy	t_gameboy;

typedef struct		s_header
{
  char			*start;
  char			nintendo[0x30];
  union
    {
      struct
	{
	  char			unused2[11];
	  char			manufacturer_code[4];
	  char			cbg_flag;
	};
      char			title[16];
    };
  short			new_licensee_code;
  char			sgb_flag;
  char			cart_type;
  char			cart_rom_size;
  char			cart_ram_size;
  char			destination_code;
  char			old_licensee_code;
  char			mask_rom_version;
  unsigned char		header_checksum;
  short			global_checksum;
}			t_header;

enum			e_cartbridge_type
{
  CT_ROM_ONLY
};

typedef struct		s_rom
{
  char			*start;
  t_header		header;
}			t_rom;

int		load_rom(t_gameboy *gb);

#endif /* !ROM_H_ */
