pkgname="openutils-date_time"
pkgver="1.0.1"
pkgrel="1"
pkgdesc="Date and time classes for C++."
arch=("x86_64" "i686")
conflicts=('openutils-date_time')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/date.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/time.hh")

sha512sums=(
	"9a1b463ba237c6a5d0ab634c942d4039f683292507da4ebf4ec5f3cd62538dd7fde0103edc8e17b413d0a494258f95f1f336e7ae481e884b5abce275665c6a23"
	"f50fa42101ab01bf81e63d899af6e2b541cc57aeeb9d3be95cc7752318c21acf1932a14042a3e609743e1082b029520175809350bc7dd42af0b987b9dc8985c8")

package() {
	echo "Date and time classes for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/date-time"
	cp "${srcdir}/date.hh" "${pkgdir}/usr/include/openutils/date-time/date.hh"
	cp "${srcdir}/time.hh" "${pkgdir}/usr/include/openutils/date-time/time.hh"
	echo "Done!"
}
