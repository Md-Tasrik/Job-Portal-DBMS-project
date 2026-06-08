# Job Portal - Database Management System Project

## 📋 Project Overview

**Job Portal** is a comprehensive web-based platform designed to bridge the gap between job seekers and employers. This system provides a centralized, efficient, and user-friendly solution for managing job postings, applications, and candidate profiles. Whether you're a job seeker looking for your next opportunity or an employer searching for qualified talent, this portal simplifies the entire recruitment process.

### Project Goal

To create a scalable, accessible, and reliable online job portal that:
- Enables job seekers to search, discover, and apply for job opportunities
- Allows employers to post job vacancies and find qualified candidates
- Provides administrative controls for system management
- Delivers a seamless user experience across all user roles

---

## 🎯 Key Features

### For Job Seekers
- **User Account Management**: Create and manage personalized profiles with resume uploads
- **Advanced Job Search**: Filter jobs by industry, location, salary range, and experience level
- **Job Applications**: Apply to jobs directly through the portal with application tracking
- **Saved Jobs**: Bookmark interesting job listings for future reference
- **Company Insights**: Browse company profiles and read reviews from other candidates
- **Profile Management**: Update personal information, skills, education, and career preferences

### For Employers
- **Company Profiles**: Create and manage comprehensive company information and branding
- **Job Posting Management**: Post, edit, and manage multiple job vacancies
- **Application Tracking**: Track all incoming applications and candidate responses
- **Applicant Management**: View candidate profiles, resumes, and qualifications
- **Analytics Dashboard**: Monitor job posting performance and application statistics
- **Company Reviews**: Access feedback and reviews from job seekers

### For Administrators
- **User Management**: Manage user accounts, permissions, and roles
- **System Monitoring**: Track platform activity and maintain system integrity
- **Data Management**: Full database control and report generation
- **Content Moderation**: Manage job postings and user-generated content
- **Reporting**: Generate comprehensive system reports

---

## 🛠️ Technology Stack

| Component | Technology |
|-----------|-----------|
| **Frontend** | HTML5, CSS3, JavaScript |
| **Backend** | PHP 8.2+ |
| **Database** | MySQL 10.4+ / MariaDB |
| **Server** | Apache Web Server |
| **Authentication** | Session-based with bcrypt password hashing |

### Language Composition
- PHP: 77.7%
- CSS: 17.9%
- JavaScript: 2.4%
- Hack: 1.3%
- C++: 0.7%

---

## 📊 Database Architecture

### Core Tables

**Users Table** - Job Seeker Profiles
```sql
- id_user (Primary Key)
- fullname, email, password
- profile_pic, resume
- address, headline, skills
- education_id, date_of_birth, age
- contact_number, gender
- role_id (Foreign Key)
```

**Company Table** - Employer Profiles
```sql
- id_company (Primary Key)
- companyname, email, password
- industry_id, establishment_date
- address, city_id, state_id
- contact_number, website
- employee_count, aboutme
- profile_pic
- active status
```

**Job_Post Table** - Job Listings
```sql
- id_jobpost (Primary Key)
- id_company (Foreign Key)
- jobtitle, description
- industry_id, job_status
- salary_range (minimum & maximum)
- location (city_id, state_id)
- experience_required
- education_qualification
- required_skills, responsibilities
- deadline, creation_timestamp
```

**Applied_Jobposts Table** - Job Applications
```sql
- id_applied (Primary Key)
- id_jobpost, id_user (Foreign Keys)
- id_company
- application_status
- application_timestamp
```

**Saved_Jobposts Table** - Bookmarked Jobs
```sql
- id_saved (Primary Key)
- id_jobpost, id_user (Foreign Keys)
- creation_timestamp
```

**Company_Reviews Table** - User Feedback
```sql
- id (Primary Key)
- company_id (Foreign Key)
- created_by (Foreign Key - User)
- review_text
- creation_timestamp
```

**Reference Tables**
- `industry`: 27 industry categories (IT, Finance, Hospitality, etc.)
- `education`: 8 education levels (Diploma to Doctoral Degree)
- `career`: 6 career experience levels
- `job_type`: Full Time, Part Time, Internship
- `states`: 8 administrative divisions in Bangladesh
- `districts_or_cities`: 64 cities/districts across Bangladesh

---

## 📁 Project Structure

```
Job-Portal-DBMS-project/
├── index.php                    # Homepage
├── login.php                    # User authentication
├── findJobs.php                 # Job search & listing
├── jobDetails.php               # Individual job details
├── browseCompanies.php          # Company directory
├── companyDetails.php           # Company profile details
├── searchJob.php                # Job search functionality
├── searchCompany.php            # Company search functionality
├── JobPortal.sql                # Database schema and sample data
│
├── includes/                    # Reusable PHP components
│   ├── conn.php                 # Database connection
│   ├── indexHeader.php          # Page headers
│   ├── indexNavbar.php          # Navigation bar
│   ├── footer.php               # Footer component
│   └── indexChat.php            # Chat functionality (optional)
│
├── dashboard/                   # User dashboards
│   ├── user_dashboard.php
│   ├── company_dashboard.php
│   └── admin_dashboard.php
│
├── process/                     # Backend logic & processing
│   ├── login_process.php
│   ├── register_process.php
│   ├── job_application.php
│   ├── job_posting.php
│   └── profile_update.php
│
├── modals/                      # Modal dialogs & popups
│   ├── login_modal.php
│   ├── register_modal.php
│   └── application_modal.php
│
├── assets/                      # Static resources
│   ├── css/                     # Stylesheets
│   ├── js/                      # JavaScript files
│   └── images/                  # Icons, logos, backgrounds
│
└── Report Generation/           # Report generation modules
    ├── application_report.php
    ├── job_report.php
    └── analytics_report.php
```

---

## 🚀 Installation & Setup

### Prerequisites
- Apache Web Server (or equivalent)
- PHP 8.2 or higher
- MySQL 10.4+ or MariaDB
- Basic knowledge of web hosting/local server setup

### Step 1: Clone the Repository
```bash
git clone https://github.com/Md-Tasrik/Job-Portal-DBMS-project.git
cd Job-Portal-DBMS-project
```

### Step 2: Database Setup
1. Open phpMyAdmin or MySQL command line
2. Create a new database:
   ```sql
   CREATE DATABASE jobportal;
   ```
3. Import the database schema:
   ```bash
   mysql -u root -p jobportal < JobPortal.sql
   ```

### Step 3: Configure Database Connection
Edit `includes/conn.php`:
```php
<?php
$host = "localhost";
$username = "root";
$password = "your_password";
$database = "jobportal";

$conn = new mysqli($host, $username, $password, $database);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>
```

### Step 4: Deploy Application
1. Copy the project folder to your web server's root directory:
   - **XAMPP**: `C:\xampp\htdocs\`
   - **WAMP**: `C:\wamp\www\`
   - **Linux**: `/var/www/html/`

2. Access the application:
   ```
   http://localhost/Job-Portal-DBMS-project/
   ```

---

## 👥 User Roles & Access

### 1. **Job Seeker (Role ID: 1)**
- Create and manage personal profiles
- Search and apply for jobs
- Save job listings for later
- Upload and manage resume
- Browse and review companies
- Track application status

### 2. **Employer/Company (Role ID: 2)**
- Create and verify company profile
- Post and manage job listings
- Track incoming applications
- View candidate profiles and resumes
- Manage application workflow
- Respond to job seeker inquiries

### 3. **Administrator (Role ID: 3)**
- Full system access and control
- Manage all user accounts
- Monitor and moderate content
- Generate system reports
- Manage reference data (industries, locations)
- System configuration and maintenance

---

## 💻 Core Functionality

### Job Search & Discovery
- **Advanced Filters**: Search by job title, industry, location, salary, experience
- **Real-time Search**: Instant job listing updates
- **Job Details**: Comprehensive job information with requirements
- **Application Tracking**: Monitor submitted applications

### Company Management
- **Company Profiles**: Detailed company information and branding
- **Job Postings**: Easy job creation and management
- **Candidate Screening**: View and manage incoming applications
- **Company Reviews**: Public feedback from job seekers

### User Profiles
- **Resume Management**: Upload and update resume files
- **Skill Showcase**: Highlight relevant skills and expertise
- **Profile Completion**: Step-by-step profile building
- **Activity History**: Track applied jobs and interactions

### Analytics & Reporting
- **Application Reports**: Track application submissions and status
- **Job Performance**: Monitor job posting popularity
- **Candidate Analytics**: Analyze applicant demographics
- **System Metrics**: Overall platform statistics

---

## 🔐 Security Features

- **Password Encryption**: bcrypt hashing for secure password storage
- **Session Management**: Secure PHP session handling
- **Input Validation**: Server-side validation of all inputs
- **Email Verification**: Account verification via email
- **Access Control**: Role-based access control (RBAC)
- **SQL Injection Prevention**: Prepared statements and parameterized queries

---

## 📝 Sample User Credentials

Default test accounts created in the database:

### Admin Account
- Email: `adminsabbir@gmail.com`
- Password: `admin123` (hashed in database)

### Sample Job Seeker
- Email: `mdsabbirhosen926@gmail.com`
- Account: Active with profile and resume

### Sample Employer
- Company: Brain Station (IT & Telecommunication)
- Email: `brainstation@gmail.com`

> **Note**: Change these credentials immediately after deployment for security purposes.

---

## 🐛 Known Issues & Future Enhancements

### Current Limitations
- Basic UI/UX (can be improved with modern frameworks)
- Limited file upload validation
- No email notification system implemented
- Basic search functionality (can be enhanced)
- No advanced filters for job recommendations

### Planned Enhancements
- [ ] Implement email notifications for job matches
- [ ] Add skill-based job recommendations
- [ ] Develop mobile-responsive design
- [ ] Integrate payment gateway for premium features
- [ ] Add messaging system between recruiters and candidates
- [ ] Implement video interview capabilities
- [ ] Add machine learning for job matching
- [ ] Create mobile application (iOS/Android)
- [ ] Implement two-factor authentication (2FA)
- [ ] Add resume parsing and skill extraction

---

## 📚 Documentation Files

- **`JobPortal.sql`**: Complete database schema with sample data
- **`includes/conn.php`**: Database connection configuration
- **`dashboard/`**: User interface modules
- **`process/`**: Backend logic and data processing

---

## 🤝 Contributing

Contributions are welcome! To contribute:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### Contribution Guidelines
- Follow PSR-12 PHP coding standards
- Test all new features thoroughly
- Update documentation for new features
- Ensure backward compatibility

---

## 📞 Support & Contact

For issues, questions, or suggestions:
- **GitHub Issues**: [Report a bug or request a feature](https://github.com/Md-Tasrik/Job-Portal-DBMS-project/issues)
- **Email**: adminsabbir@gmail.com
- **Repository**: [Job-Portal-DBMS-project](https://github.com/Md-Tasrik/Job-Portal-DBMS-project)

---

## 📄 License

This project is provided as-is for educational and commercial purposes. Modify and distribute as needed.

---

## 🙏 Acknowledgments

- **Development Team**: Md-Tasrik & Rupa
- **Framework**: Built with PHP, MySQL, HTML, CSS, and JavaScript
- **Inspiration**: Modern job portal platforms like Indeed, LinkedIn, and Bdjobs

---

## 📊 Project Statistics

- **Repository Created**: January 28, 2025
- **Last Updated**: February 1, 2026
- **Total Size**: ~74 KB
- **Language Composition**:
  - PHP: 77.7%
  - CSS: 17.9%
  - JavaScript: 2.4%
  - Hack: 1.3%
  - C++: 0.7%

---

## 🎓 Learning Outcomes

This project demonstrates proficiency in:
- Full-stack web development (LAMP stack)
- Database design and normalization
- User authentication and authorization
- RESTful API principles
- MVC architecture patterns
- PHP object-oriented programming
- MySQL query optimization
- Frontend user interface design
- Web security best practices

---

## 🔄 Version History

| Version | Date | Changes |
|---------|------|---------|
| 1.0 | Jan 28, 2025 | Initial release with core features |
| 1.1 | Feb 1, 2026 | Bug fixes and feature enhancements |

---

**Last Updated**: February 1, 2026  
**Status**: Active & Maintained  
**Contributions**: Welcome
