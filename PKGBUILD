pkgname="openutils-sstring"
pkgver="1.7.0"
pkgrel="8"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("MIT")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/prototype_err.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/binary.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/morse_code.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=(
	"d53e959a8712661dbd34489e9f7a4c5de822b066a312db1d738df5fd792446f8916812f676c95d6601bed9c8d805a15f80a8d8b7b2772e80a3fb3647a6922473"
	"aa847d067c67bec14f46b6ee4aa2404fb774f126f20a736497de2de0665134f57a32c615d74d5479f4ada8538f5c83183e94625276b2808661582dc5d52b5f6a"
	"6ecebe5630653a8bfcde5ae36e496db65cd117e6a7ead959bf7adcb2028a4d90f4a279891d50a971f24541062a08821adf3658964e5795b4cb80b97716a9794e"
	"c5633262224292305daa1218d1646c459569635765d8224424978a18560722a0fbf55145b1b3cad40c70fe8fceabb9f81d930a1addd8a84dae43fd6b2534067f"
	"d198a6983898bad68fa327c39a8a03b4e8da116882e02552f884dbc0beb14d0380f95625b345abe2e5a5f6827ed406a10f35c7f69d121b2aa75fdeb4f73a90e2")

package() {
	echo "Memory Safe String Library in C language."
	mkdir -p "${pkgdir}/usr/include/openutils/sstring"
	cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/openutils/sstring/sstring.h"
	cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/openutils/sstring/prototype_err.h"
	cp "${srcdir}/binary.h" "${pkgdir}/usr/include/openutils/sstring/binary.h"
	cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/openutils/sstring/morse_code.h"
	cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
	echo "Done!"
}
