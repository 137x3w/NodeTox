import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import List from 'material-ui/List';
import ContactListItem from './contactListItem';

const styles = theme => ({
  contactsListBar: {
    overflow: 'auto',
    minHeight: '120px',
    height: 'calc(100vh - 135px)',
    backgroundColor: theme.palette.primary.main,
  },
});

class ContactListBar extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      contacts: props.contacts || [],
    }
    this.classes = props.classes;
  }
  
  render() {
    return (    
      <Grid item align="center" className={ this.classes.contactsListBar }>
        <List disablePadding className={this.classes.contactList}>
          {
            this.state.contacts.map((item) => (
              <ContactListItem
                key={item.uid}
                nickname={item.nickname}
                statusMessage={item.statusMessage}
                avatarSrc={item.avatarSrc}
                connectionStatus={item.connectionStatus}
                unreadMessagesCount={item.unreadMessagesCount}
              />
            ))
          }          
        </List>
      </Grid>
    );
  }
}

ContactListBar.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(ContactListBar);
